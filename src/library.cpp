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
	    login();
	    if (curr_user != nullptr)
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
    BookComponent* book = new Book("Hamlet", "William Shakespeare"); 
    BookComponent* sub_genre = new BookGroup("Romance");

    sub_genre->Add(book);
   
    avail_books = new BookGroup("Drama"); 
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

void Library::login()
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
	return;
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
	    curr_user = new User(username, password);

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
    }

    inFile.close();
}






















