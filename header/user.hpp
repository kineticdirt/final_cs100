#ifndef __USER_HPP__
#define __USER_HPP__

#include "Catalog.hpp"
#include "display.hpp"
#include "display_genre.hpp"
#include "display_subgenre.hpp"
#include "display_author.hpp"
#include "display_title.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class User
{
    private:
	string username;
	string password;
	int debt;
	Catalog* all_books = nullptr;
	vector<string> borrowed;
	
    public:
	User(string, string, int, Catalog*);
	bool initialize();              //handles running user class until user logs out
	void initialize_borrowed();     //checks what books the user has borrowed
	char user_menu();               //prints available user menus	
        void view_debt();               //view current user debt
	void view_books();              //view a list of available books
	void view_borrowed();
	int get_debt() const;
	string get_username() const; 
	string get_password() const;
};

#endif //__USER_HPP__
