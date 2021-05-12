#ifndef ___BOOK__CPP___
#define ___BOOK__CPP___
#include "Book.hpp"
#include <iostream>

using namespace std;

Book::Book(string ISBN,string name,string author) : ISBN(ISBN),name(name),author(author){}

string Book::GetISBN() const {
	return ISBN;
}

string Book::Getname() const {
	return name;
}

string Book::Getauthor() const {
	return author;
}

void Book::print(ostream& out) const{
	out << "ISBN: " << ISBN << endl;
	out << "Name: " << name << endl;
	out << "Author: " << author << endl;
}

#endif // !___BOOK__CPP___

