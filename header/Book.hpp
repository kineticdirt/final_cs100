#ifndef __BOOK__HPP___
#define __BOOK__HPP___

#include <string>

using namespace std;

class Book {
private:  
	string name;
	string author;
	string isbn;
	string subgenre;

public:
	Book(string name, string author,string isbn,string subgenre){
		this->name = name;
		this->author = author;
		this->isbn = isbn;		
		this->subgenre = subgenre;
	}

	~Book() {};

	string getname() const { return name; }
	string getIsbn() const { return isbn; }	
	string getauthor() const { return author; }
	string getsubgenre() const { return subgenre; }
	void display(ostream& out) const {
		out << "Book: " << name << " by " << author << endl;
	}
};

#endif // !__BOOK__HPP___

