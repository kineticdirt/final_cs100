#ifndef __USER_HPP__
#define __USER_HPP__

#include "Catalog.hpp"
#include "display.hpp"
#include "display_genre.hpp"
#include "display_subgenre.hpp"
#include "display_author.hpp"
#include "display_title.hpp"
#include "search.hpp"
#include "search_isbn.hpp"
#include "search_author.hpp"
#include "search_title.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class User
{
    protected:
	string username;
	string password;
	int debt;
	Catalog* all_books = nullptr;
    
    public:
	vector<string> borrowed;
	User(string, string, int, Catalog*);
	~User();
	bool initialize();              //handles running user class until user logs out
	void initialize_borrowed();     //checks what books the user has borrowed
	char user_menu();               //prints available user menus	
        void view_debt();               //view current user debt
	void view_books();              //view a list of available books
	void view_borrowed();           //view a list of borrowed books
	void update_book_file();        //updates borrowed books .txt file if user borrows a new book
	void borrow_menu();
        void borrow_title(istream& in);           
	void borrow_author(istream& in);
	void borrow_isbn(istream& in);
	int get_debt() const;
	string get_username() const; 
	string get_password() const;
};

#endif //__USER_HPP__
