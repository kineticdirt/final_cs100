#ifndef  __DISPLAY__GENRE__HPP
#define	 __DISPLAY__GENRE__HPP

#include "display.hpp"
#include <string>
using namespace std;

class Display_Genre : public Display {
private:
	string genre;
public:
	Display_Genre(const string& genre) : genre(genre) {}

	void display(vector<Book*> books,ostream& out) {
		out << "Genre: " << genre << endl << endl;
		for (int i = 0; i < books.size();i++) {
			string str1 = books[i]->getgenre();
			string str2 = genre;
			bool result = iequals(str1, str2);
			if (result) {
				books[i]->display(out);
			}
		}
	}
};

#endif // ! __SEARCH__BY__GENRE__HPP

