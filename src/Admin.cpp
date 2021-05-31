#include "../header/admin.hpp"

Admin::Admin(string username, string password) : public User(username, password){}

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

bool User::initialize()
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

/*void Admin::view_books()
/*
void Admin::view_books()

{
    stringstream out;
    cout << "\nAvailable Books: " << endl;
    avail_books->display(out);    

    cout << out.str() << endl;
}
*/
