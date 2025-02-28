//
// Created by fedil on 2/16/2025.
//

#ifndef CLIBRARY_H
#define CLIBRARY_H
#include "cMember.h"
#include "cBook.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class cLibrary {
private:
    vector<cBook> _vBooks;
    // cMember _vMember;

protected:
    vector<cMember> _vMembers;

    bool isBookExist(int id);
    bool isBookExistByName(const string& name) const;

    static void displayBook(const cBook& book);

public:
    cLibrary();

    vector<cMember> &Members();
    void setMembers(const vector<cMember>& members);
    void reloadMembers();
    void reloadBooks();

    cBook* findBook(const string& name);
    cBook* modifyBook(const string& name);

    void AddBook(cBook book);
    void RemoveBook(int id);

    void BorrowBook(const string& bookName);
    void ReturnBook(const string& bookName);

    void FindBookByName();
    void ModifyingBook();

    void ShowAvailableBooks();
    void ShowLibraryStatus();

    friend class cMember;
    friend class cBook;

};



#endif //CLIBRARY_H
