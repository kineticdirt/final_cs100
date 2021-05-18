#include "../header/library.hpp"
#include <limits>
#include <sstream>

Library::Library()
{
    acc_file_name = "accounts.txt";
}

Library::Library(string acc_file_name)
{
    this->acc_file_name = acc_file_name;
}

void Library::initialize()
{
    char choice;

    //creates list of available books
    read_books(); 
	
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
	cin.ignore(); 

	if (choice == '1')	
	{
	    create_acc();
	}
        else if (choice == '2' || choice == '3')
	{
	    return choice;
	}
    	else if (choice != '1')
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
    
    outFile << username << "\n";
    outFile << password << "\n";
    outFile << "User \n";

    outFile.close();

    cout << "\nAccount " << username << " successfully created!" << endl;

    menu();
}

bool Library::login()
{
    ifstream inFile;
    string username;
    string password;
    string read_user;   //username to read from accounts.txt
    string read_pass;   //password to read from accounts.txt
    string read_admin;  //checks for admin privileges

    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    inFile.open(acc_file_name);
    if (!inFile.is_open())
    {
      	cout << acc_file_name << " does not exist!" << endl;
	return false;
    } 

    while (!inFile.eof())
    {
	/* Reads User Info From File */
 	getline(inFile, read_user);
       	getline(inFile, read_pass);
        getline(inFile, read_admin);

	/* Validates User Exists */
  	if (read_user == username && read_pass == password)
	{
	    //sets current user information
	    curr_user = new User(username, password, avail_books);

	    /* Outputs Welcome Message */
	    cout << "\nWelcome, ";
	    cout << username;
 
	    //only prints if User is Admin
            if (read_admin == "Admin")
	    {
 		cout << " (Admin)";
            }

            cout << "!" << endl;

	    break;
	}	
    }

    if (read_user != username && read_pass != password)
    {
	cout << "\nWrong username/password!" << endl;
	return false;
    }

    inFile.close();

    return true;
}






















