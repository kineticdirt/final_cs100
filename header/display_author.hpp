#ifndef __DISPLAY__AUTHOR__HPP
#define __DISPLAY__AUTHOR__HPP

#include "display.hpp"
#include <string>
using namespace std;

class Display_Author : public Display {
private:
	string author;
public:
	Display_Author(const string& author) : author(author) {}
	void display(vector<Book*> books,ostream& out) {
		out << "Author: " << author << endl << endl;
		for (int i = 0; i < books.size();i++) {
				string str1 = books[i]->getauthor();
				string str2 = author;
				bool result = iequals(str1, str2);
				if (result) {
					books[i]->display(out);
					break;
				}
				
		}
	}
};

#endif // !__DISPLAY__SUBGENRE__HPP

