//
// Created by fedil on 2/17/2025.
//

#include "cMember.h"
#include "cData.h"
#include "cLibrary.h"
#include "cUserInterface.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

cMember::cMember(int id, string name, string password, string phoneNumber, bool isAdmin) {
    this->_id = id;
    this->_name = name;
    this->_password = password;  // ✅ Add this line
    this->_phoneNumber = phoneNumber;
    this->_isAdmin = isAdmin;  // ✅ Use the provided isAdmin parameter
    this->_markForDeletion = false;
}

cMember::cMember() {
    this->_id = 0;
    this->_name = "";
    this->_phoneNumber = "";
    this->_password = "";
    this->_isAdmin = false;
    this->_markForDeletion = false;
}


void cMember::setId(int id) {
    this->_id = id;
}
void cMember::setName(string name) {
    this->_name = name;
}
void cMember::setPhoneNumber(string phoneNumber) {
    this->_phoneNumber = phoneNumber;
}
void cMember::setPassword(string password) {
    this->_password = password;
}
void cMember::setMarkForDeletion(bool markForDeletion) {
    this->_markForDeletion = markForDeletion;
}

void cMember::setIsAdmin(bool isAdmin) {
    _isAdmin = isAdmin;
}

int cMember::Id() const {
    return this->_id;
}
string cMember::Name() const {
    return this->_name;
}
string cMember::PhoneNumber() const {
    return this->_phoneNumber;
}
string cMember::Password() const {
    return this->_password;
}
bool cMember::MarkForDeletion() const {
    return _markForDeletion;
}

bool cMember::isMemberExist(cLibrary& lib, string userName, string userPassword, cMember& member)  {
    for (auto& m : lib._vMembers) {
        if (userName == m.Name() && userPassword == m.Password()) {
            member = m;
            return true;
        }
    }
    return false;
}
bool cMember::isAdmin() const {
    return this->_isAdmin;
}

cMember cMember::readMember(cLibrary& lib) {
    cMember member;

    // Automatically assign ID (increment last member's ID)
    int newId = (lib._vMembers.empty()) ? 1 : lib._vMembers.back().Id() + 1;
    member._id = newId;

    cout << "Assigned ID: " << newId << endl;

    cout << "Enter password: ";
    getline(cin, member._password);

    cout << "Enter Name: ";
    getline(cin, member._name);

    cout << "Enter Phone Number: ";
    getline(cin, member._phoneNumber);

    cout << "Make The member admin? (1 = Yes, 0 = No): ";
    int adminChoice;
    while (!(cin >> adminChoice) || (adminChoice != 0 && adminChoice != 1)) {
        cout << "Invalid input! Enter 1 for Admin or 0 for Member: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    member._isAdmin = (adminChoice == 1);

    return member;
}

void cMember::displayMemberInfo() const {
    cout << "Member ID   : " << _id << "\n"
        <<  "Name        : " << _name << "\n"
        <<  "Phone Number: " << _phoneNumber << "\n"
        << "----------------------------\n";
}

void cMember::addMember(cLibrary& lib, const cMember &member)  {
    for (const auto& m : lib._vMembers) {
        if (m.Name() == member.Name() && m.Password() == member.Password()) {
            if (m.isAdmin()) {
                cout << "This user is already an admin!" << endl;
            } else {
                cout << "Member already exists!" << endl;
            }
            return;
        }
    }

    lib._vMembers.push_back(member);
    cData::SaveMemberDataToFile("./membersData.txt", lib._vMembers);
}
void cMember::removeMember(cLibrary& lib, int memberId) {
    for (auto& m : lib.Members()) {  // Use accessor instead of direct access
        if (m.Id() == memberId) {
            if (m.isAdmin() && m.Name() == "Admin1") {
                cout << "You cannot delete this user!! Please enter another ID." << endl;
                return;
            }

            PrintMemberRecord(m);

            char answer;
            while (true) {
                cout << "\t\t\tAre you sure you want to remove this member? (y/n): ";
                cin >> answer;

                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter 'y' for Yes or 'n' for No.\n";
                    continue;
                }

                if (answer == 'y' || answer == 'Y') {
                    m.setMarkForDeletion(true);  // ✅ Mark for deletion
                    cData::SaveMemberDataToFile("./membersData.txt", lib.Members());  // Use getter
                    lib.reloadMembers();
                    cout << "The member was marked for deletion!\n";
                    return;
                }
                else if (answer == 'n' || answer == 'N') {
                    cout << "Member removal cancelled.\n";
                    return;
                }
                else {
                    cout << "Invalid input! Please enter 'y' for Yes or 'n' for No.\n";
                }
            }
        }
    }

    cout << "Cannot find member with ID " << memberId << endl;
}

void cMember::AddMemberScreen(cLibrary& lib) {
    cout << "\t\t\t" << string(80, '-') << endl;
    cout << "\t\t\t\t\t\tAdd Member Screen" << endl;
    cout << "\t\t\t" << string(80, '-') << endl;

    addMember(lib, readMember(lib));
}
void cMember::removeMemberScreen(cLibrary& lib) {
    cout << "\t\t\t" << string(80, '-') << endl;
    cout << "\t\t\t\t\t\tRemove Member Screen" << endl;
    cout << "\t\t\t" << string(80, '-') << endl;

    int memberId = cUserInterface::readId();
    removeMember(lib, memberId);
}

void cMember::PrintMemberRecordWithId(cLibrary &lib, int memberId) {
    cout << "\t\t\t" << string(80, '-') << endl;
    for (auto& m : lib._vMembers) {
        if (m.Id() == memberId) {
            cout << "\t\t\t\t\t" << "Name        : " << m.Name() << endl;
            cout << "\t\t\t\t\t" << "Password    : " << m.Password() << endl;
            cout << "\t\t\t\t\t" << "Phone Number: " << m.PhoneNumber() << endl;
            return;
        }
    }
    cout << "\t\t\t" << string(80, '-') << endl;
}
void cMember::PrintMemberRecord(const cMember &member) {
    const string sRoll = member._isAdmin ? "Admin" : "Member";
    cout << "\t\t\t" << "| " << member.Id() << setw(17) << "| " << member.Name() << setw(25) << "| " << member.
            PhoneNumber() << setw(10) << "| " << sRoll << endl;
}
void cMember::displayAllMembers(cLibrary& lib) {
    cout << "\t\t\t" << string(90, '-') << endl;
    cout << "\t\t\t" << "| Id" << setw(20) << "| Name" << setw(38) << "| Phone Number" << setw(21) << "| Roll" << endl;
    cout << "\t\t\t" << string(90, '-') << endl;
    for (auto& m : lib.Members()) {
        PrintMemberRecord(m);
    }
}
