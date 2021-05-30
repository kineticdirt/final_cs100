#ifndef __DISPLAY__SUBGENRE__HPP
#define __DISPLAY__SUBGENRE__HPP

#include "display.hpp"
#include <string>
using namespace std;

class Display_Subgenre : public Display {
private:
	string subgenre;
public:
	Display_Subgenre(const string& subgenre) : subgenre(subgenre) {}
	void display(vector<vector<Book*>> books,ostream& out) {
		out << "SubGenre: " << subgenre << endl << endl;
		for (int i = 0; i < books.size();i++) {
			for (int j = 0;j < books[i].size();j++) {
				string str1 = books[i][j]->getsubgenre();
				string str2 = subgenre;
				bool result = iequals(str1, str2);
				if (result) {
					books[i][j]->display(out);
				}
			}
		}
	}
};

#endif // !__DISPLAY__SUBGENRE__HPP

