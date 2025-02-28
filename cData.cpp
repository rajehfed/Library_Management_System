//
// Created by fedil on 2/17/2025.
//

#include "cData.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

cData::cData() {
    _booksFileName = "./libraryData.txt";
    _membersFileName = "./membersData.txt";

    _vMembersData = LoadMemberDataFromFile(_membersFileName);
    _vBooksData = LoadBooksDataFromFile(_booksFileName);

    cMember m1;
    m1.setId(0);
    m1.setName("Admin");
    m1.setPassword("1234");
    m1.setPhoneNumber("+213 6 56 67 51 68");
    m1.setIsAdmin(true);

    _vMembersData.push_back(m1);
}

vector<string> cData::Split(string S1, string Delim) {
    vector<string> vString;

    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

cMember cData::convertStringToMember(vector<string> vMembersData) {
    cMember member;

    member.setId(stoi(vMembersData[0]));
    member.setPassword(vMembersData[1]);
    member.setName(vMembersData[2]);
    member.setPhoneNumber(vMembersData[3]);
    member.setIsAdmin(static_cast<bool>(stoi(vMembersData[4])));

    return member;
}
cBook cData::convertStringToBook(vector<string> vBooksData) {
    cBook book;

    book.setId(stoi(vBooksData[0]));
    book.setTitle(vBooksData[1]);
    book.setAuthor(vBooksData[2]);
    book.setQuantity(static_cast<short>(stoi(vBooksData[3])));
    book.setIsAvailable(static_cast<bool>(stoi(vBooksData[3])));
    return book;
}

string cData::ConvertMemberToString(cMember member) {
    string sWord = "";

    sWord += to_string(member.Id()) + "/%%/";
    sWord += member.Password() + "/%%/";
    sWord += member.Name() + "/%%/";
    sWord += member.PhoneNumber() + "/%%/";
    sWord += to_string(member.isAdmin());

    return sWord;
}
string cData::ConvertBookToString(cBook book) {
    string sWord = "";

    sWord += to_string(book.Id()) + "/%%/";
    sWord += book.Title() + "/%%/";
    sWord += book.Author() + "/%%/";
    sWord += to_string(book.Quantity()) + "/%%/";
    sWord += to_string(book.IsAvailable());

    return sWord;
}

vector<cMember> cData::LoadMemberDataFromFile(string fileName) {
    vector<cMember> vMembersData;

    ifstream MyFile(fileName);

    if (MyFile.is_open()) {
        string sLine;
        while (getline(MyFile, sLine)) {
            vector<string> vTokens = Split(sLine, "/%%/");
            if (vTokens.size() == 5) {
                cMember member = convertStringToMember(vTokens);
                vMembersData.push_back(member);
            }
        }
        MyFile.close();
    }
    else {
        cout << "Error: Could not open file " << fileName << "\n";
        return {};
    }

    return vMembersData;
}
vector<cBook> cData::LoadBooksDataFromFile(string fileName) {
    vector<cBook> vBooksData;
    fstream MyFile;
    MyFile.open(fileName, ios::in);

    if (MyFile.is_open()) {
        string sLine;
        while (getline(MyFile, sLine)) {
            vector<string> vTokens = Split(sLine, "/%%/");

            if (vTokens.size() == 5) {
                cBook book = convertStringToBook(vTokens);
                vBooksData.push_back(book);
            }
        }
        MyFile.close();
    }
    else {
        cout << "Error: Could not open file " << fileName << "\n";
        return {};
    }

    return vBooksData;
}

void cData::SaveMemberDataToFile(string fileName, vector<cMember>& vMembersData) {
    ofstream myFile(fileName);
    if (!myFile) {
        cout << "Error: Could not open file " << fileName << " for writing.\n";
        return;
    }

    for (auto& member : vMembersData) {
        if (!member.MarkForDeletion()) {  // ✅ Use the correct getter
            myFile << ConvertMemberToString(member) << "\n";
            if (myFile.fail()) {
                cout << "Error: Failed to write to " << fileName << "\n";
                myFile.close();  // ✅ Close file before exiting
                return;
            }
        }
    }

    myFile.close();  // ✅ Ensure file is closed before confirming success
    cout << "Successfully written to file " << fileName << "\n";
}
void cData::SaveBooksDataToFile(string fileName, vector<cBook>& vBooksData) {
    ofstream myFile(fileName);
    if (!myFile) {
        cout << "Error: Could not open file " << fileName << "for Writing!\n";
        return;
    }
    for (auto& book : vBooksData) {
        myFile << ConvertBookToString(book) << "\n";
        if (myFile.fail()) {
            cout << "Error: Failed to write to " << fileName << "\n";
            break;
        }
    }
    myFile.close();
}

bool cData::isUserNameValid(const string &userName) const {
    for (auto& user : _vMembersData) {
        if (user.Name() == userName)
            return true;
    }
    return false;
}
bool cData::isUserPasswordValid(const string &userPassword) const {
    for (auto& user : _vMembersData) {
        if (user.Password() == userPassword)
            return true;
    }
    return false;
}
