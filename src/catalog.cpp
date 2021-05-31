#ifndef __CATALOG__CPP
#define __CATALOG__CPP
#include "../header/Catalog.hpp"

using namespace std;

Catalog::Catalog() {
	display = nullptr;
	s = nullptr;
}

Catalog::~Catalog() {
	vector<Book*>::iterator pos;
	for (pos = books.begin();pos != books.end(); ++pos) {
		Book* book = *pos;
		delete book;
	}
	books.clear();
	delete display;
	delete s;
}

void Catalog::set_search(Search* new_search) {
	delete s;
	s = new_search;
}

Book* Catalog::getbook() {
	return s->search(books);
}

void Catalog::set_display(Display* new_display) {
	delete display;
	display = new_display;
}

Catalog* Catalog::instance = 0;

void Catalog::print(ostream& out) const {
	display->display(books,out);
}
#endif // !__CATALOG__CPP

