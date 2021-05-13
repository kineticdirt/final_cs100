#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Library 
{
    private:
	string acc_file_name;
        	
    public:
	Library();
	Library(string);
	void menu();            //prints library interface menu
        void create_acc();      //creates a new account
	void login();           //user or admin login
};

#endif //__LIBRARY_HPP__
