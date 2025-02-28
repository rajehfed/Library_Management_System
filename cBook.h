//
// Created by fedil on 2/16/2025.
//

#ifndef CBOOK_H
#define CBOOK_H
#include <string>
#include <iostream>
using namespace std;


class cBook {
private:
    int _id;
    string _title;
    string _author;
    bool _isAvailable;
    short _quantity;

public:
    cBook();
    cBook(int id, string title, string author, int quantity);

    void setId(int id);
    void setTitle(string title);
    void setAuthor(string author);
    void setIsAvailable(bool isAvailable);
    void setQuantity(int quantity);

    int Id() const;
    string Title() const;
    string Author() const;
    bool IsAvailable() const;
    short Quantity() const;

    void markAsReturned();
    void markAsBorrowed();

    void increaseQuantity(short quantity);
    void decreaseQuantity(short quantity);

    static cBook ReadBook();

};



#endif //CBOOK_H
