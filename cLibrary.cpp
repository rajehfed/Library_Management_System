//
// Created by fedil on 2/16/2025.
//

#include "cLibrary.h"
#include "cUserInterface.h"
#include "cBook.h"
#include "cData.h"
#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

cLibrary::cLibrary() {
    _vBooks = cData::LoadBooksDataFromFile("./libraryData.txt");
}

vector<cMember> &cLibrary::Members() {
    return _vMembers;
}
void cLibrary::setMembers(const vector<cMember> &members) {
    _vMembers = members;
}
void cLibrary::reloadMembers() {
    _vMembers = cData::LoadMemberDataFromFile("./membersData.txt");
}
void cLibrary::reloadBooks() {
    _vBooks = cData::LoadBooksDataFromFile("./libraryData.txt");
}

cBook *cLibrary::findBook(const string &name) {
    for (auto& book : _vBooks) {
        if (book.Title() == name) {
            return &book;
        }
    }
    return nullptr;
}
cBook *cLibrary::modifyBook(const string &name) {
    if (isBookExistByName(name)) {
        cBook *book = findBook(name);
        if (!book) return nullptr;  // ✅ Prevents null pointer dereferencing

        string title, author;
        short quantity = 0;

        cout << "Enter new title: ";
        cin.ignore();  // ✅ Clears newline from the buffer before using getline
        getline(cin, title);

        cout << "Enter new author: ";
        getline(cin, author);

        cout << "Enter new quantity: ";
        cin >> quantity;

        book->setTitle(title);
        book->setAuthor(author);
        book->setQuantity(quantity);

        return book;
    }
    return nullptr;
}

bool cLibrary::isBookExist(int id) {
    for (auto& book : _vBooks) {
        if (id == book.Id()) {
            return true;
        }
    }
    return false;
}
bool cLibrary::isBookExistByName(const string &name) const {
    for (auto& book : _vBooks) {
        if (book.Title() == name) {
            return true;
        }
    }
    cout << "\t\t\t\t\t\t" << name << " does not exist" << endl;
    return false;
}

void cLibrary::AddBook(cBook Book) {
    if (!isBookExist(Book.Id())) {
        _vBooks.push_back(Book);
        cData::SaveBooksDataToFile("./libraryData.txt", _vBooks);
        reloadBooks();
        cout << "Book added Successfully!!" << endl;
    }
    else
        cout << "Book already exists" << endl;
}
void cLibrary::RemoveBook(int id) {
    for (int i = 0; i < _vBooks.size(); i++) {
        if (_vBooks[i].Id() == id) {
            _vBooks.erase(_vBooks.begin() + i);
            cData::SaveBooksDataToFile("./libraryData.txt", _vBooks);
            cout << "Book removed" << endl;
            return;
        }
    }
    cout << "Sorry, the book with id '" << id << "' is not found." << endl;
}

void cLibrary::displayBook(const cBook& book) {
    cout << left << setw(10) << book.Id()
                 << setw(30) << book.Title()
                 << setw(25) << book.Author()
                 << setw(20) << book.Quantity()
                 << endl;
}
void cLibrary::ShowAvailableBooks() {
    _vBooks = cData::LoadBooksDataFromFile("./libraryData.txt");
    if (_vBooks.empty()) {
        cout << "There are no books in this library." << endl;
        return;
    }
    cout << left << setw(10) << "ID"
              << setw(30) << "Title"
              << setw(25) << "Author"
              << setw(25) << "Quantity"
              << "\n";
    cout << string(65, '-') << "\n";
    for (auto& book : _vBooks) {
        if (book.IsAvailable())
            displayBook(book);
    }
}
void cLibrary::ShowLibraryStatus() {
    cout << "Library Statistics \n";
    cout << string(80, '-') << "\n";
    cout << "Total Books  : " << _vBooks.size() << endl;
    cout << "Total Members: " << _vMembers.size() << endl;
}

void cLibrary::FindBookByName() {

    cout << "\t\t\t" << string(80, '-') << "\n";
    cout << "\t\t\t\t\t\t" << "Find book by name screen" << endl;
    cout << "\t\t\t" << string(80, '-') << "\n";

    const string bookName = cUserInterface::readBookName();
    cBook* book = findBook(bookName);

    if (book != nullptr) {
        cout << "\t\t\t\t" << "\033[1;32mBook found : " << book->Id() << "\033[0m" << endl;
        cout << "\t\t\t\t";
        displayBook(*book);
    } else {
        cout << "\033[31mBook not found :-( \033[0m" << endl;
    }
}
void cLibrary::ModifyingBook() {
    cout << "\t\t\t" << string(80, '-') << "\n";
    cout << "\t\t\t\t\t\t" << "Modify book by name screen" << endl;
    cout << "\t\t\t" << string(80, '-') << "\n";

    string bookName = cUserInterface::readBookName();

    cBook* book = findBook(bookName);

    if (!book) {  // ✅ Fix: Check if book exists before dereferencing
        cout << "\t\t\tBook not found!\n";
        return;
    }

    displayBook(*book);

    char a;
    do {
        cout << "\t\t\t\t\t\t" << "Are you sure this is the target book? {y/n}: ";
        cin >> a;
        a = toupper(a);
    } while (a != 'Y' && a != 'N');

    if (a == 'Y') {  // ✅ Fix: Only modify if user confirms
        modifyBook(bookName);
        cData::SaveBooksDataToFile("./libraryData.txt", _vBooks);
        reloadBooks();
        cout << "\t\t\t\t\t\tBook Updated Successfully!!" << endl;
    } else {
        cout << "\t\t\tModification cancelled.\n";
    }
}

void cLibrary::BorrowBook(const string& bookName) {
    if (_vBooks.empty()) {
        cout << "There are no books in this library." << endl;
        return;
    }
    for (auto& book : _vBooks) {
        if (book.Title() == bookName) {
            if (book.IsAvailable()) {
                book.markAsBorrowed();
                cData::SaveBooksDataToFile("./libraryData.txt", _vBooks);
                cout << "The book with the name \'" << bookName << "\' is successfully borrowed!!" << endl;
                return;
            } else {
                cout << "Sorry, the book '" << bookName << "' is already borrowed." << endl;
                return;
            }
        }
    }
    cout << "The book '" << bookName << "' does not exist in the library." << endl;
}
void cLibrary::ReturnBook(const string& bookName) {
    for (auto& book : _vBooks) {
        if (book.Title() == bookName) {
            book.markAsReturned();
            cData::SaveBooksDataToFile("./libraryData.txt", _vBooks);
            cout << "The book with the name \'" << bookName << "\' is successfully returned!!" << endl;
            return;
        }
    }
    cout << "The book '" << bookName << "' does not exist in the library." << endl;
}