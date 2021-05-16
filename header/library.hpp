#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include "user.hpp"

using namespace std;

class Library
{
    private:
	string acc_file_name;    //file containing all accounts
	User* curr_user = nullptr;         //current user logged in
        	
    public:
	Library();
	Library(string);
	void initialize();      //initializes library system
	char menu();            //prints library interface menu 
        void create_acc();      //creates a new account
	void login();           //user or admin login
};

#endif //__LIBRARY_HPP__
