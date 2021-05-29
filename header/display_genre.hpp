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

	void display(vector<vector<Book*>> books,ostream& out) {
		out << "Genre: " << genre << endl << endl;
		for (int i = 0; i < books.size();i++) {
			for (int j = 0;j < books[i].size();j++) {
				string str1 = books[i][j]->getgenre();
				string str2 = genre;
				bool result = iequals(str1, str2);
				if (result) {
					books[i][j]->display(out);
				}
				else{
					break;
				}
			}
		}
	}
};

#endif // ! __SEARCH__BY__GENRE__HPP

