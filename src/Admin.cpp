
#include "../header/admin.hpp"
#include <iostream>
#include <string>


Admin::Admin(string username, string password) {
	  this->username = username;
	  this->password = password;
	  ofstream outFile;
		outFile.open("admin_account.txt", std::ios::app);
	  if (!inFile.is_open())
		{
			  cout << "admin_accounts.txt" << " does not exist!" << endl;
	   } 	else {
			  cout << get_username() << " : " << get_password() << endl;
		}
}

bool Admin::initialize()
{
    char choice = ' ';
    choice = user_menu();
    if (choice == '1')
    {
	view_books();
    }
    else if (choice == '3')
    {
	borrow_a_book();
    }
    else if (choice == '4')
    {
		view_debt();
    }
    else if (choice == '5')
    {
		view_borrowed();
    }
    else if (choice == '0')
    {
	return false;
    }
    else if (choice == ' ') 
    {
		admin_menu();
    }
    
    return true;
}


char Admin::admin_menu()
{
    char choice = ' ';
   
    cout << endl;
    cout << "========================" << endl;    
    cout << "Admin: " << this->username << endl;
    cout << "========================" << endl;
    cout << "1. View Books" << endl;
    cout << "2. Search Books" << endl;
    cout << "3. Assign book to User" << endl;
    cout << "4. View Users" << endl;
	  cout << "5. View Users" << endl;
    cout << "0. Main Menu" << endl;

   
   while (choice != '1' && choice != '0')
    {
 	cin >> choice;

	if (choice == '1' || choice == '0' || choice == '2' || choice == '3' || choice == '4' || choice == '5')
	{
	    return choice;
	}
	else
	{
	    cout << "Enter a valid menu option!" << endl;
	    return ' ';
	}
    }
}


string Admin::get_username() const 
{
    return username;
}

string Admin::get_password() const
{
    return password;
}
void Admin::borrow_user_book(string passwrd, string user_username, string title) {
	if(passwrd == getPassword()) {
		ifstream file;
		file.open("borrowed_books.txt", std::fstream::in);
		if(!file.is_open()) {
			cout << "Failed to open borrowed_books" << endl;
			return;
		}
		string* checker;
		while(getline(file, checker, ' ')){
			string title1;
			if(user_username.compare(*checker)) {
				file >> title1;
				if(title1.compare(title)) {
					return;
			}
		}
		file.close();
		ofstream outfile("borrowed_books.txt", std::fstream::app)
		outfile << user_username<<" " << title << endl;
        	outfile.close()
	} else { 
		cout << "incorrect password, reenter correct password"
		string passwrd1;
		cin >> passwrd1; 
		borrow_user_book(passwrd1, user_username, title);
	}
}
