#ifndef __SEARCH__ISBN__HPP____
#define __SEARCH__ISBN__HPP____

#include "search.hpp"
#include <string>
using namespace std;

class Search_ISBN :public Search {
private:
	string isbn;
public:
	Search_ISBN(const string& isbn) : isbn(isbn) {}

	Book* search(vector<Book*> books) {
		for (int i = 0; i < books.size();i++) {
			if (books[i]->getIsbn() == isbn) {
				return books[i];
			}
		}

		return nullptr;
	}
};



#endif // !__SEARCH__TITLE__HPP

