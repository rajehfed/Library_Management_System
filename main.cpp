#include <iostream>
#include <limits>
#include "cBook.h"
#include "cData.h"
#include "cLibrary.h"
#include "cUserInterface.h"
using namespace std;

// cMember currentMember;
// cLibrary lib;
//
// void MainMenuScreen();
// void TransactionsMenuScreen(cLibrary& library);
//
// int readNumber(const short From, const short To) {
//     int num;
//     do {
//         cout << "Please enter your choice (" << From << "," << To << "): ";
//         cin >> num;
//
//         if (cin.fail() || num < From || num > To) {
//             cout << "⚠️ Invalid input! Please enter a number between " << From << "and" << To << ".\n";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } else {
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             break;
//         }
//     } while (true);
//
//     return num;
// }
// string readBookName() {
//     string bookName;
//     cout << "Please enter your book name: ";
//     getline(cin, bookName);
//     return bookName;
// }
//
// int readId() {
//     int id;
//     cout << "Please enter your id: ";
//     cin >> id;
//     return id;
// }
// void GoBackToTheMainManu() {
//     cout << "Press Enter to continue..." << endl;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     MainMenuScreen();
// }
// void GoBackToTransactionsMenu(cLibrary& library) {
//     cout << "Press Enter to continue..." << endl;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     TransactionsMenuScreen(library);
// }
// enum enMainMenuOptions {eShow = 1, eBorrow = 2, eReturn = 3, eTransactions = 4, eQuit = 6};
// enum enAdminTransactionsOptions {eAddMemeber = 1, eRemoveMemeber = 2, eAddBook = 3, eRemoveBook = 4, eShowMembers = 5};
//
// void PerformeTransaction(cLibrary& lib, enAdminTransactionsOptions transactions) {
//     switch (transactions) {
//         case eAddMemeber:
//             system("CLS");
//             cMember::AddMemberScreen(lib);
//             GoBackToTransactionsMenu(lib);
//             break;
//
//         case eRemoveMemeber:
//             system("CLS");
//             cMember::removeMember(lib, readId());
//             GoBackToTransactionsMenu(lib);
//             break;
//
//         case eAddBook:
//             system("cls");
//             lib.AddBook(cBook::ReadBook());
//             GoBackToTransactionsMenu(lib);
//             break;
//
//         case eRemoveBook:
//             system("cls");
//             lib.RemoveBook(readId());
//             GoBackToTransactionsMenu(lib);
//             break;
//
//         case eShowMembers:
//             system("CLS");
//             cMember::displayAllMembers(lib);
//             GoBackToTransactionsMenu(lib);
//             break;
//
//         default:
//             system("CLS");
//             GoBackToTheMainManu();
//             break;
//
//     }
// }
// void TransactionsMenuScreen(cLibrary& library) {
//     system("cls");
//     // if (currentMember.isAdmin()) {
//         cout << "\n\n\n";
//         cout << "\t\t\t" << string(80, '-') << endl;
//         cout << "\t\t\t\t\t\tTransactions Screen" << endl;
//         cout << "\t\t\t" << string(80, '-') << endl;
//         cout << "\t\t\t\t\t\t[1] Add Member" << "\n";
//         cout << "\t\t\t\t\t\t[2] Remove Member" << "\n";
//         cout << "\t\t\t\t\t\t[3] Add Book" << "\n";
//         cout << "\t\t\t\t\t\t[4] Remove Book" << "\n";
//         cout << "\t\t\t\t\t\t[5] Show All Members" << "\n";
//         cout << "\t\t\t\t\t\t[6] Back to Main Menu" << "\n";
//         PerformeTransaction(library, static_cast<enAdminTransactionsOptions>(readNumber(1, 6)));
//     // }
// }
//
// void PerformeMainMenuOptions(cLibrary& library, enMainMenuOptions mainMenuOptions) {
//     switch (mainMenuOptions) {
//         case eShow:
//             system("cls");
//             library.ShowAvailableBooks();
//             GoBackToTheMainManu();
//             break;
//
//         case eBorrow:
//             system("cls");
//             library.BorrowBook(readBookName());
//             GoBackToTheMainManu();
//             break;
//
//         case eReturn:
//             system("cls");
//             library.ReturnBook(readBookName());
//             GoBackToTheMainManu();
//             break;
//
//         case eTransactions:
//             system("cls");
//             TransactionsMenuScreen(library);
//             GoBackToTheMainManu();
//             break;
//
//         case eQuit:
//             system("cls");
//             return;
//     }
// }
// void MainMenuScreen() {
//     system("cls");
//     cout << "\n\n\n";
//     cout << "\t\t\t" << string(80, '-') << endl;
//     cout << "\t\t\t\t\t\tWelcome To The Main Menu Library!" << endl;
//     cout << "\t\t\t" << string(80, '-') << endl;
//     cout << "\t\t\t\t\t\t[1] Show Available Books" << "\n";
//     cout << "\t\t\t\t\t\t[2] Borrow Book" << "\n";
//     cout << "\t\t\t\t\t\t[3] Return Book" << "\n";
//     cout << "\t\t\t\t\t\t[4] Transactions" << "\n";
//     cout << "\t\t\t\t\t\t[6] Exit" << "\n";
//     PerformeMainMenuOptions(lib, static_cast<enMainMenuOptions>(readNumber(1, 6)));
// }
//
// void login() {
//     string userName;
//     string userPassword;
//     lib.setMembers(cData::LoadMemberDataFromFile("./membersData.txt"));
//
//     cout << "Please enter your username: ";
//     getline(cin, userName);
//
//     cout << "Please enter your password: ";
//     getline(cin, userPassword);
//
//     if (cMember::isMemberExist(lib, userName, userPassword))
//         MainMenuScreen();
//     else
//         cout << "Invalid Username or Password! Please try again!" << endl;
//
// }

int main() {
    cUserInterface ui;
    ui.login();
    return 0;
}
