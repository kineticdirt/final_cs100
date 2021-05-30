#ifndef __USER_HPP__
#define __USER_HPP__

#include "Catalog.hpp"
#include <iostream>
#include <sstream>

using namespace std;

class User
{
    private:
	string username;
	string password;
	int debt;
	
    public:
	User(string, string, int);
	bool initialize();              //handles running user class until user logs out
	char user_menu();               //prints available user menus	
        void view_debt();               //view current user debt
	void view_books();              //view a list of available books
	int get_debt() const;
	string get_username() const; 
	string get_password() const;
};

#endif //__USER_HPP__
