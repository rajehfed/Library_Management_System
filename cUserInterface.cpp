//
// Created by fedil on 2/23/2025.
//

#include "cUserInterface.h"
#include <iostream>
#include <limits>
#include <string>
#include "cLibrary.h"
#include "cData.h"
#include "cBook.h"
#include "cMember.h"
using namespace std;

cLibrary lib;

int cUserInterface::readNumber(const short From, const short To) {
    int num;
    do {
        cout << "Please enter your choice (" << From << "," << To << "): ";
        cin >> num;

        if (cin.fail() || num < From || num > To) {
            cout << "⚠️ Invalid input! Please enter a number between " << From << "and" << To << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    } while (true);

    return num;
}
string cUserInterface::readName(const string &message) {
    cout << "\t\t\t" << message << endl;
    string name;
    getline(cin, name);
    return name;
}

string cUserInterface::readBookName() {
    string bookName;
    cout << "Please enter your book name: ";
    getline(cin, bookName);
    return bookName;
}
int cUserInterface::readId() {
    int id;
    cout << "Please enter your id: ";
    cin >> id;
    return id;
}

void cUserInterface::MainMenuScreen() {
    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t" << string(80, '-') << endl;
    cout << "\t\t\t\t\t\tWelcome To The Main Menu Library!" << endl;
    cout << "\t\t\t" << string(80, '-') << "\n" << endl;
    cout << "\t\t\t\t\t\t\033[105m  [1] Show Available Books \033[0m" << "\n\n";
    cout << "\t\t\t\t\t\t\033[42m  [2] Borrow Book          \033[0m" << "\n\n";
    cout << "\t\t\t\t\t\t\033[44m  [3] Return Book          \033[0m" << "\n\n";
    cout << "\t\t\t\t\t\t\033[46m  [4] Find Book            \033[0m" << "\n\n";
    cout << "\t\t\t\t\t\t\033[43m  [5] Transactions         \033[0m" << "\n\n";
    cout << "\t\t\t\t\t\t\033[45m  [6] Library Status       \033[0m" << "\n\n";
    cout << "\t\t\t\t\t\t\033[41m  [7] Exit                 \033[0m" << "\n\n";
    PerformeMainMenuOptions(lib, static_cast<enMainMenuOptions>(readNumber(1, 7)));
}
void cUserInterface::PerformeMainMenuOptions(cLibrary& library, enMainMenuOptions mainMenuOptions) {
    switch (mainMenuOptions) {
        case eShow:
            system("cls");
            library.ShowAvailableBooks();
            GoBackToTheMainManu();
        break;

        case eBorrow:
            system("cls");
            library.BorrowBook(readBookName());
            GoBackToTheMainManu();
        break;

        case eReturn:
            system("cls");
            library.ReturnBook(readBookName());
            GoBackToTheMainManu();
        break;

        case eFind:
            system("cls");
            library.FindBookByName();
            GoBackToTheMainManu();
        break;

        case eTransactions:
            system("cls");
            TransactionsMenuScreen(library);
            GoBackToTheMainManu();
        break;

        case eStatus:
            system("cls");
            library.ShowLibraryStatus();
            GoBackToTheMainManu();
        break;

        case eQuit:
            system("cls");
        return;
    }
}
void cUserInterface::GoBackToTheMainManu() {
    cout << "Press Enter to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    MainMenuScreen();
}

void cUserInterface::TransactionsMenuScreen(cLibrary& library) {
    system("cls");
    if (currentMember.isAdmin()) {
        cout << "\n\n\n";
        cout << "\t\t\t" << string(80, '-') << endl;
        cout << "\t\t\t\t\t\t\tTransactions Screen" << endl;
        cout << "\t\t\t" << string(80, '-') << "\n" << endl;
        cout << "\t\t\t\t\t\t     \033[46m  [1] Add Member        \033[0m" << "\n\n";
        cout << "\t\t\t\t\t\t     \033[46m  [2] Remove Member     \033[0m" << "\n\n";
        cout << "\t\t\t\t\t\t     \033[101m  [3] Add Book          \033[0m" << "\n\n";
        cout << "\t\t\t\t\t\t     \033[101m  [4] Remove Book       \033[0m" << "\n\n";
        cout << "\t\t\t\t\t\t     \033[101m  [5] Modify Book       \033[0m" << "\n\n";
        cout << "\t\t\t\t\t\t     \033[101m  [6] Modify Member     \033[0m" << "\n\n";
        cout << "\t\t\t\t\t\t     \033[102m  [7] Show All Members  \033[0m" << "\n\n";
        cout << "\t\t\t\t\t\t     \033[102m  [8] Back to Main Menu \033[0m" << "\n\n";
        PerformeTransaction(library, static_cast<enAdminTransactionsOptions>(readNumber(1, 8)));
    }
    cout << "You Are Not Enable To Do this extension!!" << endl;
}
void cUserInterface::PerformeTransaction(cLibrary& lib, enAdminTransactionsOptions transactions) {
    switch (transactions) {
        case eAddMemeber:
            system("CLS");
            cMember::AddMemberScreen(lib);
            GoBackToTransactionsMenu(lib);
        break;

        case eRemoveMemeber:
            system("CLS");
            cMember::removeMember(lib, readId());
            GoBackToTransactionsMenu(lib);
        break;

        case eAddBook:
            system("cls");
            lib.AddBook(cBook::ReadBook());
            GoBackToTransactionsMenu(lib);
        break;

        case eRemoveBook:
            system("cls");
            lib.RemoveBook(readId());
            GoBackToTransactionsMenu(lib);
        break;

        case eModify:
            system("cls");
            lib.ModifyingBook();
            GoBackToTransactionsMenu(lib);
        break;

        case eModifyMember:
            system("cls");
            cMember::ModifyMemberByName(lib);
            GoBackToTransactionsMenu(lib);
        break;

        case eShowMembers:
            system("CLS");
            cMember::displayAllMembers(lib);
            GoBackToTransactionsMenu(lib);
        break;

        default:
            system("CLS");
            GoBackToTheMainManu();
        break;

    }
}
void cUserInterface::GoBackToTransactionsMenu(cLibrary& library) {
    cout << "Press Enter to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    TransactionsMenuScreen(library);
}

void cUserInterface::login() {
    string userName;
    string userPassword;
    lib.setMembers(cData::LoadMemberDataFromFile("./membersData.txt"));

    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t" << string(80, '-') << endl;
    cout << "\t\t\t\t\t\tWelcome To Login Screen!" << endl;
    cout << "\t\t\t" << string(80, '-') << endl;

    cout << "\t\t\t\033[94mPlease enter your username: \033[0m";
    getline(cin, userName);

    cout << "\t\t\t\033[94mPlease enter your password: \033[0m";
    getline(cin, userPassword);

    if (cMember::isMemberExist(lib, userName, userPassword, currentMember))
        MainMenuScreen();
    else {
        cout << "\t\t\t\033[91mInvalid Username or Password! Please try again!\033[0m" << endl;
        cin.ignore();
    }
}
