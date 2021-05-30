#include "../header/user.hpp"

User::User(string username, string password, int debt, Catalog* books)
{
    this->username = username;
    this->password = password;
    this->debt = debt;
    this->all_books = books;
    initialize_borrowed();
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
	user_menu();
    }
    
    return true;
}

void User::initialize_borrowed()
{
    ifstream inFile;
    string temp;

    inFile.open("borrowed_books.txt");
    if (!inFile.is_open())
    {
	cout << "borrowed_books.txt" << " does not exist!" << endl;
    } 

    while (getline(inFile, temp))
    {
	//reads and ignores the first "begin" string
	if (temp == "begin")
	{
	    getline(inFile, temp);
	}

	if (temp == this->username)
	{
	    //gets the first book and ignores username
	    getline(inFile, temp);

	    //adds user's borrowed books to vector of borrowed books
	    while (temp != "end")
	    {
		borrowed.push_back(temp);
		getline(inFile, temp);
	    }
	}	
    }
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
    cout << "5. View Borrowed Books" << endl;
    cout << "0. Main Menu" << endl;

    /* User Input */
    while (choice != '1' && choice != '0')
    {
 	cin >> choice;

	if (choice == '1' || choice == '0' || choice == '4' || choice == '5')
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
    stringstream out;
    char choice;

    cout << "1. View all books" << endl;
    cout << "2. View by genres" << endl;
    cout << "3. View by subgenres" << endl;
    cout << "4. View by titles" << endl;
    cout << "5. View by authors" << endl;

    cin >> choice;

    if (choice == '2')
    {
	cin.ignore(256, '\n');
	cout << "1. Novels" << endl;
	cout << "2. Magazines" << endl;
	cout << "3. Comic Books" << endl;
	cout << "4. Poems" << endl; 	
	cin >> choice;

	if (choice == '1')
	{
	    all_books->set_display(new Display_Genre("Novel"));
	    all_books->print(out);
	}
    }    
}

void User::view_borrowed()
{
    cout << this->username << "'s borrowed books: " << endl;
   
    for (int i = 0; i < borrowed.size(); i++)
    {
	cout << "\t" << borrowed.at(i) << endl;
    } 
    cout << endl;
}















