#ifndef ___DISPLAY__HPP
#define ___DISPLAY__HPP
#include "Catalog.hpp"
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class Display {
public:
	virtual ~Display() = default;
	virtual void display(vector<Book*> books,ostream& out) = 0;

	
    bool iequals(const string& a, const string& b)
    {
        unsigned int sz = a.size();
        if (b.size() != sz)
            return false;
        for (unsigned int i = 0; i < sz; ++i)
            if (tolower(a[i]) != tolower(b[i]))
                return false;
        return true;
    }
};

#endif // !1

