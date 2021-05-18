#include "../header/admin.hpp"

Admin::Admin(string username, string password)
{
    this->username = username;
    this->password = password;
}

bool User::initialize()
{
    char choice = ' ';
    choice = user_menu();
    if (choice == '1')
    {
	    view_books();
    }
    else  //if user enters '0'
    {
	    return false;
    }
    
    return true;
}

char Admin::admin_menu()
{
    char choice = ' ';
    /* Menu Output */
    cout << endl;
    cout << "========================" << endl;    
    cout << "Admin: " << this->username << endl;
    cout << "========================" << endl;
    cout << "1. View Books" << endl;
    cout << "2. Search Books" << endl;
    cout << "3. Assign book to User" << endl;
    cout << "4. View Users" << endl;
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

void Admin::view_info()
{
    cout << "\nUsername: " << get_username() << endl;
    cout << "Password: " << get_password() << endl;
}

string Admin::get_username() const 
{
    return username;
}

string Admin::get_password() const
{
    return password;
}

void Admin::view_books()
{
    stringstream out;
    cout << "\nAvailable Books: " << endl;
    avail_books->display(out);    

    cout << out.str() << endl;
}
