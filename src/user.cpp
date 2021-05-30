#include "../header/user.hpp"

User::User(string username, string password, int debt)
{
    this->username = username;
    this->password = password;
    this->debt = debt;
}

bool User::initialize()
{
    stringstream out;
    char choice = ' ';
 
    choice = user_menu();
    
    if (choice == '1')
    {
	view_books();
    }
    else if (choice == '4')
    {
	view_debt();
    }
    else if (choice == '0')
    {
	return false;
    }
    else if (choice == ' ') 
    {
	user_menu();
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

	if (choice == '1' || choice == '0' || choice == '4')
	{
	    return choice;
	}
	else
	{
	    cout << "Enter a valid menu option!" << endl;
	    return ' ';
	    //cin.clear();
	}
    }
}

void User::view_debt()
{
    cout << "Total debt: $" << get_debt() << endl;
}

int User::get_debt() const
{
    return debt;
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















