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
	void display(vector<Book*> books,ostream& out) {
		out << "SubGenre: " << subgenre << endl << endl;
		for (int i = 0; i < books.size();i++) {
				if (subgenre == books[i]->getsubgenre()) {
					books[i]->display(out);
				}
		}
	}
};

#endif // !__DISPLAY__SUBGENRE__HPP

