#ifndef __ADMIN_HPP__
#define __ADMIN_HPP__
#include "BookComponent.hpp"
#include "user.hpp"
#include <iostream>
#include <sstream>

using namespace std;

class Admin
{
    private:
	string username;
	string password;
  	User* admin_access;
	
	
    public:
	Admin(string, string);
	bool initialize();     //handles running user class until user logs out
	char user_menu();      //prints available admin menu
        void view_user_info();   //view current user information
        void view_info();      //view username & password
	void view_books();     //view a list of available books
	string get_username() const; 
	string get_password() const;
};

#endif //__ADMIN_HPP__
