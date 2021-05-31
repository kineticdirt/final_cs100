#ifndef ___SEARCH__HPP
#define ___SEARCH__HPP
#include "Catalog.hpp"
#include "Book.hpp"
#include <string>
#include <iostream>

using namespace std;

class Search {
public:
    virtual ~Search() = default;
    virtual Book* search(vector<Book*> books)  = 0;


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

