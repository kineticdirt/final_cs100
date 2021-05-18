#include "../header/BookGroup.hpp"
#include <iostream>
using namespace std;

BookGroup::BookGroup(string group) {
	this->group = group;
}

BookGroup::~BookGroup() {
	vector<BookComponent*>::iterator pos;
	for (pos = Book_List.begin();pos != Book_List.end();pos++) {
		BookComponent* r = *pos;
		delete r;
	}
	Book_List.clear();
}

void BookGroup::Add(BookComponent* addbook) {
	Book_List.push_back(addbook);
}

void BookGroup::Remove(BookComponent* book ) {
	vector<BookComponent*>::iterator pos;
	for (pos = Book_List.begin();pos != Book_List.end();pos++) {
		if (*pos == book) {
			Book_List.erase(pos);
   			break;
		}
    }
}

void BookGroup::Reorganize_books() {

}

void BookGroup::Edit_book() {

}

void BookGroup::display(ostream& out) const {
	out << "Book Group: " << group << endl << endl;
	for (auto& it : Book_List) {
		out << "\t";
		it->display(out);
		out << endl;
	}


}
