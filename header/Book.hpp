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
	string genre;

public:
	Book(string name, string author,string isbn,string genre,string subgenre){
		this->name = name;
		this->author = author;
		this->isbn = isbn;		
		this->genre = genre;
		this->subgenre = subgenre;
	}

	~Book() {};

	string getname() const { return name; }
	string getIsbn() const { return isbn; }	
	string getauthor() const { return author; }
	string getsubgenre() const { return subgenre; }
	string getgenre() const { return genre; }

	
	void display(ostream& out) const {
		out << "Book: " << name << " by " << author << endl;
	}
};

#endif // !__BOOK__HPP___

