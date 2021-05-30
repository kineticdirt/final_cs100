#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

#include "user.hpp"
#include "Book.hpp"
#include "Catalog.hpp"

using namespace std;

class Library
{
    private:
		string acc_file_name;         //file containing all accounts
		User* curr_user = nullptr;    //current user logged in
        vector<User*> users;      //stores all users
		vector<Admin*> users;	      //stores the users

    protected:
		Catalog* catalog = nullptr;  //protected so the user/admin can access
        	
    public:
		Library();
		~Library();
		Library(string);
		void initialize();      //initializes library system
		void read_users();      //reads in users from .txt file
		void init_catalog();    //Initializes single Catalog object
		char menu();            //prints library interface menu 
		void create_acc();      //creates a new account
		bool login();           //user or admin login
};

#endif //__LIBRARY_HPP__
