#include "../header/library.hpp"
#include <limits>

Library::Library()
{
    acc_file_name = "accounts.txt";
}

Library::Library(string acc_file_name)
{
    this->acc_file_name = acc_file_name;
}

Library::~Library()
{
    if (curr_user != nullptr)
    {
 	delete curr_user; 
    }

    for (auto& i : users)
    {
	User* delete_user = i;
 	delete delete_user;
    }

    users.clear();

    if (avail_books != nullptr)
    {
	delete avail_books;
    }
}

void Library::initialize()
{
    char choice;

    //creates list of available books
    read_books(); 

    //creates list of users
    read_users();

    while (true)
    {
	choice = menu();
  	
        if (choice == '2')
	{
	    if (login())
	    {
		//loops user interface until user logs out
		while (curr_user->initialize()) { }
	    }
	}
        else if (choice == '3')
	{
	    cout << "Goodbye!" << endl;
	    break;
	}	
    }
}

//this function should read a list of books from a text file,
//but we'll create books manually for now
void Library::read_books()
{       
    BookComponent* book1 = new Book("Hamlet", "William Shakespeare"); 
    BookComponent* book2 = new Book("Twilight" , "Stephanie Myers");
    BookComponent* book3 = new Book("The Crucible", "Arthur Miller");
    BookComponent* sub_genre = new BookGroup("Romance");

    sub_genre->Add(book1);
    sub_genre->Add(book2);
   
    avail_books = new BookGroup("Drama"); 

    avail_books->Add(book3);
    avail_books->Add(sub_genre);
}

void Library::read_users()
{
    ifstream inFile;
    string username;
    string password;
    string temp;
    
    inFile.open(acc_file_name);
    if (!inFile.is_open())
    {
	cout << acc_file_name << " does not exist!" << endl;
    }    

    while (getline(inFile, temp))
    {
	username = temp;
	getline(inFile, temp);
	password = temp;
	getline(inFile, temp);

	User* new_user = new User(username, password, avail_books);
	this->users.push_back(new_user);
    }
}

char Library::menu()
{
    char choice = ' ';
   
    /* Menu Output */ 
    cout << endl;
    cout << "========================" << endl;    
    cout << "------Library Menu------" << endl;
    cout << "========================" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
 
    /* User Input */ 
    while (choice != '1' && choice != '2' && choice != '3')
    {	
 	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choice == '1')	
	{
	    create_acc();
	}
        else if (choice == '2' || choice == '3')
	{
	    return choice;
	}
    	else if (choice != '1' && choice != '2' && choice != '3')
    	{
	    cout << "Enter a valid menu option!" << endl;
    	}
    }
}

void Library::create_acc()
{
    ofstream outFile;
    string username;
    string password;

    outFile.open(acc_file_name, std::ios::app);
    if (!outFile.is_open())
    {
    	cout << acc_file_name << " does not exist!" << endl;
        menu();
    }
 
    cout << "Enter a username: ";
    getline(cin, username);
    cout << "Enter a password: ";
    getline(cin, password);
   
    //outputs new user info to user .txt file 
    outFile << username << "\n";
    outFile << password << "\n";
    outFile << "User \n";

    outFile.close();

    cout << "\nAccount " << username << " successfully created!" << endl;

    //adds new user to vector containing total users
    User* new_user = new User(username, password, avail_books); 
    this->users.push_back(new_user);

    //menu();
}

bool Library::login()
{
    ifstream inFile;
    string username;
    string password;

    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    for (int i = 0; i < users.size(); i++)
    {
    	if (username == users.at(i)->get_username() && 
            password == users.at(i)->get_password())
	{
	    //sets current user information
	    curr_user = new User(username, password, avail_books);

	    /* Outputs Welcome Message */
	    cout << "\nWelcome, " << username << "!" << endl;

	    return true;
	}
    }

    cout << "Wrong Username/Password!" << endl;

    return false;
}






















