#ifndef __BOOK__HPP___
#define __BOOK__HPP___

#include <string>
#include "BookComponent.hpp"
#include <iostream>
using namespace std;

class Book : public BookComponent{
private:
	string name;
	string author;

public:
	Book(string name, string author) : BookComponent() {
		this->name = name;
		this->author = author;
	}

	~Book() {};

	string getname() const { return name; }

	string getauthor() const { return author; }

	void display(ostream& out) const {
		out << "\t" << "Book: " << name << " by " << author << endl;
	}
};

#endif // !__BOOK__HPP___

