#ifndef ___BOOK__CPP___
#define ___BOOK__CPP___
#include "Book.hpp"
#include <iostream>

using namespace std;

Book::Book(BookNode* booklist){
	this->booklist = booklist;
}

Book::~Book() {
	delete [] booklist;
}

string Book::GetISBN() const {
	auto s = to_string(booklist->ISBN); // CONVERT INT TO STRING
	return s;
}

string Book::Getname() const {
	return booklist->name;
}

string Book::Getauthor() const {
	return booklist->author;
}

string Book::Getgenre() const {
	return booklist->genre;
}

void Book::print(ostream& out) const {
	out << "ISBN: " << booklist->ISBN << endl;
	out << "Name: " << booklist->name << endl;
	out << "Author: " << booklist->author << endl;
	out << "Genre: " << booklist->genre << endl;
}

#endif // !___BOOK__CPP___

