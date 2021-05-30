#ifndef __DISPLAY__TITLE__HPP
#define __DISPLAY__TITLE__HPP

#include "display.hpp"
#include <string>
using namespace std;

class Display_Title : public Display {
private:
	string title;
public:
	Display_Title(const string& title) : title(title) {}
	void display(vector<Book*> books,ostream& out) {
		out << "Title: " << title << endl << endl;
			for (int i=0;i < books.size();i++) {
				string str1 = books[i]->getname();
				string str2 = title;
				bool result = iequals(str1, str2);
				if (result) {
					books[i]->display(out);
				}
		}
	}
};

#endif // !__DISPLAY__SUBGENRE__HPP

