#ifndef __BOOKGROUP__CPP
#define __BOOKGROUP__CPP

#include "BookGroup.hpp"
#include <iostream>
using namespace std;

BookGroup::BookGroup(string group) : BookComponent() {
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

void BookGroup::Remove(BookComponent*) {

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

#endif // !__BOOKGROUP__CPP

