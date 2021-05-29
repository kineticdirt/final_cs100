#ifndef __CATALOG__CPP
#define __CATALOG__CPP
#include "../header/catalog.hpp"

Catalog::Catalog() {
	display = nullptr;
}

Catalog::~Catalog() {
	delete display;
}

Catalog* Catalog::instance = 0;

void Catalog::set_display(Display* new_display) {
	delete display;
	display = new_display;
}

void Catalog::print(ostream& out) const {
	display->display(books,out);
}
#endif // !__CATALOG__CPP

