//
// Created by fedil on 2/17/2025.
//

#ifndef CDATA_H
#define CDATA_H
#include <iostream>
#include "cMember.h"
#include "cBook.h"
#include <vector>
using namespace std;


class cData {
private:
    vector<cMember> _vMembersData;
    vector<cBook> _vBooksData;
    string _booksFileName;
    string _membersFileName;

protected:
    static vector<string> Split(string S1, string Delim = "/%%/");

public:
    cData();
    static cMember convertStringToMember(vector<string> vMembersData);
    static cBook convertStringToBook(vector<string> vBooksData);

    static string ConvertMemberToString(cMember member);
    static string ConvertBookToString(cBook book);

    static vector<cMember> LoadMemberDataFromFile(string fileName);
    static vector<cBook> LoadBooksDataFromFile(string fileName);

    static void SaveMemberDataToFile(string fileName, vector<cMember>& vMembersData);
    static void SaveBooksDataToFile(string fileName, vector<cBook>& vBooksData);

    bool isUserNameValid(const string &userName) const;
    bool isUserPasswordValid(const string &userPassword) const;
};



#endif //CDATA_H
