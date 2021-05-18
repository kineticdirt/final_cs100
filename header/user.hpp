#ifndef __USER_HPP__
#define __USER_HPP__

#include "BookComponent.hpp"
#include <iostream>
#include <sstream>

using namespace std;

class User
{
    private:
	string username;
	string password;
	BookComponent* avail_books = nullptr;
	
    public:
	User(string, string, BookComponent*&);
	bool initialize();     //handles running user class until user logs out
	char user_menu();      //prints available user menus	
        void view_my_info();   //view current user information
	void view_books();     //view a list of available books
	string get_username() const; 
	string get_password() const;
};

#endif //__USER_HPP__
