#ifndef __ADMIN_HPP__
#define __ADMIN_HPP__
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
	bool initialize();              //handles running admin class until user logs out
	char admin_menu();               //prints available user menus              
	void view_books();              //view a list of available books
	void view_user_books();		//views user's checkout history
	void update_book_file();        //updates borrowed books .txt file if user borrows a new book
        void borrow_user_book(string passwrd, string user_username, string title);        
	string get_username();
	string get_password();
	void printBook(string username, string title);
};

#endif //__ADMIN_HPP__

