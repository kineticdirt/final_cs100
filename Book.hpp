#ifndef __BOOK__HPP___
#define __BOOK__HPP___

#include <string>

using namespace std;

struct BookNode {
	int ISBN;
	string name;
	string author;
	string genre;
	BookNode(int ISBN,string name,string author,string genre): ISBN(ISBN),name(name),author(author),genre(genre){}
};

class Book {
private:
	BookNode* booklist;

public:
	Book(BookNode*);
	~Book();
	string GetISBN() const;
	string Getname() const;
	string Getauthor() const;
	string Getgenre() const;
	void print(ostream& out) const;
};

#endif // !__BOOK__HPP___

