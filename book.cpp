#include <iostream>
#include "book.h"

// === CONSTRUCTEURS ===
Book::Book() : title(""), author(""), isbn(""), isAvailable(false), borrowerName("") {

}

Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {

}

// === GETTERS ===
string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return isbn;
}

bool Book::getAvailability() const {
    return isAvailable;
}

string Book::getBorrowerName() const {
    return borrowerName;
}

// === SETTERS ===
void Book::setTitle(const string &title) {
    this->title = title;
}

void Book::setAuthor(const string &author) {
    this->author = author;
}

void Book::setISBN(const string &isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(const bool available) {
    this->isAvailable = available;
}

void Book::setBorrowerName(const string &name) {
    this->borrowerName = name;
}

// === METHODS ===
void Book::checkOut(const string &borrower) {
    this->setBorrowerName(borrower);
    this->setAvailability(false);
}

void Book::returnBook() {
    this->setBorrowerName("");
    this->setAvailability(true);
}

string Book::toString() const {
    return "[" + this->getISBN() + "] " + this->getTitle() + ", Par " + this->getAuthor();
}

string Book::toFileFormat() const {
    string line = this->getTitle() + "|" + this->getAuthor() + "|" + this->getISBN() + "|";

    if (this->getAvailability()) {
        line += "1|";
    } else {
        line += "0|" + this->getAuthor();
    }

    return line;
}

void Book::fromFileFormat(const string &line) {
    string tbl[5]; // [title][author][isbn][isAvailableStr][borrowerName]
    string newLine = line;

    for (int i = 0; i < 4; i++) {
        tbl[i] = newLine.substr(0, newLine.find('|'));
        newLine = newLine.substr(tbl[i].length() + 1);
    }

    tbl[4] = newLine;
    

    this->setTitle(tbl[0]);
    this->setAuthor(tbl[1]);
    this->setISBN(tbl[2]);
    this->setBorrowerName(tbl[4]);

    try {
        if (tbl[3] == "1") {
            this->setAvailability(true);
        } else if (tbl[3] == "0") {
            this->setAvailability(false);
        } else {
            throw (tbl[3]);
        }
    } catch (string isAvailable) {
        cout << "Impossible de mettre à jour la disponibilité" << endl;
        cout << "Donnée: " << isAvailable << endl;
    }
}