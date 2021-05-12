#ifndef __BOOK__HPP___
#define __BOOK__HPP___

#include <string>

using namespace std;

class Book {
private:
	string ISBN;
	string name;
	string author;

public:
	Book(string,string,string);
	~Book() {};
	string GetISBN() const;
	string Getname() const;
	string Getauthor() const;
	void print(ostream& out) const;
};

#endif // !__BOOK__HPP___

