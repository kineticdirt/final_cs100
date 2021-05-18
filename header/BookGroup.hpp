#ifndef __BOOKGROUP__HPP__
#define __BOOKGROUP__HPP__
#include "BookComponent.hpp"
#include <vector>
#include <string>

using namespace std;

class BookGroup :public BookComponent {
private:
	vector <BookComponent*> Book_List;
	string group;
public:
	BookGroup(string);
	~BookGroup();
	void Add(BookComponent*);
	void Remove(BookComponent*);
	void Reorganize_books();
	void Edit_book();
	void display(ostream& out) const;
	
};

#endif // !__BOOKGROUP__HPP__

