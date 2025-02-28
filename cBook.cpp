//
// Created by fedil on 2/16/2025.
//

#include "cBook.h"
#include "cLibrary.h"
#include <limits>
#include <iostream>
#include <string>
using namespace std;

cBook::cBook(int id, string title, string author, int quantity) {
    this->_id = id;
    this->_title = title;
    this->_author = author;
    this->_quantity = quantity;
    this->_isAvailable = true;
}
cBook::cBook() {
    this->_id = 0;
    this->_title = "";
    this->_author = "";
    this->_quantity = 0;
    this->_isAvailable = true;
}

void cBook::setId(int id) {
    this->_id = id;
}
void cBook::setTitle(string title) {
    this->_title = title;
}
void cBook::setAuthor(string author) {
    this->_author = author;
}
void cBook::setIsAvailable(bool isAvailable) {
    this->_isAvailable = isAvailable;
}
void cBook::setQuantity(int quantity) {
    this->_quantity = quantity;
}

int cBook::Id() const {
    return this->_id;
}
string cBook::Title() const {
    return this->_title;
}
string cBook::Author() const {
    return this->_author;
}
bool cBook::IsAvailable() const {
    return this->_isAvailable;
}
short cBook::Quantity() const {
    return this->_quantity;
}

void cBook::markAsBorrowed() {
    decreaseQuantity(1);
    if (Quantity() == 0) {
        setIsAvailable(false);
    }
}
void cBook::markAsReturned() {
    if (Quantity() == 0) {
        increaseQuantity(1);
        setIsAvailable(true);
    }
    else {
        increaseQuantity(1);
    }
}

void cBook::increaseQuantity(short quantity) {
    setQuantity(Quantity() + quantity);
}
void cBook::decreaseQuantity(short quantity) {
    if (quantity > Quantity()) {
        cout << "Quantity exceeded" << endl;
    } else {
        setQuantity(Quantity() - quantity);
    }
}

cBook cBook::ReadBook() {
    cBook book;
    cout << "Please enter the book id: ";
    cin >> book._id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Please enter the book title: ";
    getline(cin, book._title);

    cout << "Please enter the author: ";
    getline(cin, book._author);

    cout << "Please enter the quantity[You Cannot Make 0]: ";
    cin >> book._quantity;
    while (book._quantity == 0) {
        cout << "Please enter the quantity[You Cannot Make 0]: ";
        cin >> book._quantity;
    }

    book._isAvailable = true;
    return book;
}
