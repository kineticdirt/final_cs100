#ifndef __SEARCH__AUTHOR__HPP____
#define __SEARCH__AUTHOR__HPP____

#include "search.hpp"
#include <string>
using namespace std;

class Search_Author :public Search {
private:
	string author;
public:
	Search_Author(const string& author) : author(author) {}

	Book* search(vector<Book*> books) {
		for (int i = 0; i < books.size();i++) {
			string str1 = books[i]->getauthor();
			string str2 = author;
			bool result = iequals(str1, str2);
			if (result) {
				return books[i];
			}
		}

		return nullptr;
	}
};



#endif // !__SEARCH__TITLE__HPP

