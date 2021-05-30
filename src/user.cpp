#include "../header/user.hpp"

User::User(string username, string password)
{
    this->username = username;
    this->password = password;
}

bool User::initialize()
{
    stringstream out;
    char choice = ' ';
 
    choice = user_menu();
    
    if (choice == '1')
    {
	view_books(out);
    }
    else  //if user enters '0'
    {
	return false;
    }
    
    return true;
}

char User::user_menu()
{
    char choice = ' ';

    /* Menu Output */
    cout << endl;
    cout << "========================" << endl;    
    cout << "User: " << this->username << endl;
    cout << "========================" << endl;
    cout << "1. View Books" << endl;
    cout << "2. Search Books" << endl;
    cout << "3. Borrow A Book" << endl;
    cout << "4. View Debt" << endl;
    cout << "0. Main Menu" << endl;

    /* User Input */
    while (choice != '1' && choice != '0')
    {
 	cin >> choice;

	if (choice == '1' || choice == '0')
	{
	    return choice;
	}
	else
	{
	    cout << "Enter a valid menu option!" << endl;
	    cin.clear();
	}
    }
}

void User::view_my_info()
{
    cout << "\nUsername: " << get_username() << endl;
    cout << "Password: " << get_password() << endl;
}

string User::get_username() const 
{
    return username;
}

string User::get_password() const
{
    return password;
}

void User::view_books()
{
    cout << "\nAvailable Books: " << endl;
}















