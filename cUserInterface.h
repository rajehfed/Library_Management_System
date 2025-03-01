//
// Created by fedil on 2/23/2025.
//

#ifndef CUSERINTERFACE_H
#define CUSERINTERFACE_H
#include<iostream>
#include <string>
#include "cLibrary.h"
#include "cBook.h"
#include "cMember.h"
using namespace std;


class cUserInterface {
private:
    enum enAdminTransactionsOptions {eAddMemeber = 1, eRemoveMemeber = 2, eAddBook = 3, eRemoveBook = 4, eModify = 5, eModifyMember = 6, eShowMembers = 7};
    enum enMainMenuOptions {eShow = 1, eBorrow = 2, eReturn = 3, eFind = 4, eTransactions = 5, eStatus = 6, eQuit = 7};
    cMember currentMember;

public:
    int readNumber(const short From, const short To);
    static string readName(const string& message);
    static string readBookName();
    static int readId();

    void GoBackToTheMainManu();
    void PerformeMainMenuOptions(cLibrary& library, enMainMenuOptions mainMenuOptions);
    void MainMenuScreen();

    void GoBackToTransactionsMenu(cLibrary& library);
    void PerformeTransaction(cLibrary& lib, enAdminTransactionsOptions transactions);
    void TransactionsMenuScreen(cLibrary& library);

    void login();

};



#endif //CUSERINTERFACE_H
