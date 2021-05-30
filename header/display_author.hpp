#ifndef __DISPLAY__AUTHOR__HPP
#define __DISPLAY__AUTHOR__HPP

#include "display.hpp"
#include <iostream>
#include <string>
using namespace std;

class Display_Author : public Display {
private:
	string author;
public:
	Display_Author(const string& author) : author(author) {}
	void display(vector<Book*> books,ostream& out) {
		vector<Book*>::iterator pos;
		out << "Author: " << author << endl << endl;
		for (pos = books.begin(); pos != books.end();pos++) {
				Book* book = *pos;
				string str1 = book->getauthor();
				string str2 = author;
				bool result = iequals(str1, str2);
				if (result) {
					book->display(out);
				}
				
				
		}
	}
};

#endif // !__DISPLAY__SUBGENRE__HPP

