#include "../header/BookGroup.hpp"
#include <iostream>
using namespace std;

BookGroup::BookGroup(string group) {
	this->group = group;
}

BookGroup::~BookGroup() {
	for (auto& it : Book_List) {
		BookComponent* bookcomponent = it;
		delete bookcomponent;
	}
	Book_List.clear();
}

void BookGroup::Add(BookComponent* addbook) {
	Book_List.push_back(addbook);
}

void BookGroup::Remove(BookComponent* book) {
    for (auto& it : Book_List) {
        BookComponent* bookcomponent = it;
        if (bookcomponent == book) {
            Book_List.erase(it);
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
