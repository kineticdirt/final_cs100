#ifndef ___BOOKCOMPONENT__HPP
#define ___BOOKCOMPONENT__HPP
#include <iostream>
using namespace std;
class BookComponent {
public:
	BookComponent() {}
	virtual ~BookComponent() {}
	virtual void Add(BookComponent*) {}
	virtual void Remove(BookComponent*) {}
	virtual void Reorganize_books() {}
	virtual void Edit_book() {}
	virtual void display(ostream& out) const = 0;			
};


#endif // !___BOOKCOMPONENET__HPP

