#ifndef __SEARCH__TITLE__HPP____
#define __SEARCH__TITLE__HPP____

#include "search.hpp"
#include <string>
using namespace std;

class Search_Title :public Search {
private:
	string title;
public:
	Search_Title(const string& title) : title(title) {}

	Book* search(vector<Book*> books) {
		for (int i = 0; i < books.size();i++) {
			string str1 = books[i]->getname();
			string str2 = title;
			bool result = iequals(str1, str2);
			if (result) {
				return books[i];
			}
		}
		
		return nullptr;
	}
};



#endif // !__SEARCH__TITLE__HPP

