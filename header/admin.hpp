#ifndef __ADMIN_HPP__
#define __ADMIN_HPP__
#include "user.hpp"
#include <iostream>
#include <sstream>

using namespace std;

class Admin : public User
{
    private:
  	User* admin_access;
	
	
    public:
	Admin(string, string);
	bool initialize();              //handles running admin class until user logs out
	char admin_menu();               //prints available user menus              
	void view_borrowed();           //view a list of borrowed books
	void update_book_file();        //updates borrowed books .txt file if user borrows a new book
        void borrow_user_book();        
};

#endif //__ADMIN_HPP__
