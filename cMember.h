#pragma once
#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

// Forward declaration of cLibrary to avoid circular dependency
class cLibrary;

class cMember {
private:
    int _id;
    std::string _password;
    std::string _name;
    std::string _phoneNumber;
    bool _isAdmin;
    bool _markForDeletion;

public:
    cMember(int id, std::string name, std::string password, std::string phoneNumber, bool isAdmin);
    cMember();

    void setId(int id);
    void setName(std::string name);
    void setPhoneNumber(std::string phoneNumber);
    void setPassword(std::string password);
    void setMarkForDeletion(bool markForDeletion);
    void setIsAdmin(bool isAdmin);

    int Id() const;
    std::string Name() const;
    std::string PhoneNumber() const;
    std::string Password() const;
    bool MarkForDeletion() const;

    static bool isMemberExist(cLibrary& lib, std::string userName, std::string userPassword, cMember& member);
    bool isAdmin() const;

    static cMember readMember(cLibrary& lib);
    void displayMemberInfo() const;

    static void addMember(cLibrary& lib, const cMember &member);
    static void removeMember(cLibrary& lib, int memberId);

    static void AddMemberScreen(cLibrary& lib);
    static void removeMemberScreen(cLibrary& lib);

    static void PrintMemberRecordWithId(cLibrary& lib, int memberId);
    static void PrintMemberRecord(const cMember& member);
    static void displayAllMembers(cLibrary& lib);
};

#endif // MEMBER_H
