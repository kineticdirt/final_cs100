#ifndef __CATALOG__CPP
#define __CATALOG__CPP
#include "../header/Catalog.hpp"

Catalog::Catalog() {
	display = nullptr;
}

Catalog::~Catalog() {
	vector<Book*>::iterator pos;
	for (pos = books.begin();pos != books.end(); ++pos) {
		Book* book = *pos;
		delete book;
	}
	books.clear();
	delete display;
}

void Catalog::set_display(Display* new_display) {
	delete display;
	display = new_display;
}

void Catalog::print(ostream& out) const {
	display->display(books,out);
}
#endif // !__CATALOG__CPP

