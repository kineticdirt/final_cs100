#include "../header/library.hpp"
#include "../header/Catalog.hpp"

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
    delete catalog;

    if (curr_user != nullptr)
    {
 	delete curr_user; 
    }

    for (int i = 0; i < users.size(); i++)
    {
	delete users[i];
    }

    if (curr_admin != nullptr)
    {
        delete curr_admin;
    }

    for (int i = 0; i < admins.size(); i++)
    {
        delete admins[i];
    }

    users.clear();
    admins.clear();
}

void Library::initialize()
{
    char choice;
    
    //initializes Catalog object
    init_catalog();

    //creates list of users
    read_users();

    //creates list of admins
    read_admins();

    //reads books available in Catalog
    catalog->read_books();

    while (true)
    {
	choice = menu();
  	
        if (choice == '2')
	{
	    if (login())
	    {
		//loops user interface until user logs out
		while (curr_user->initialize()) { }

	        delete curr_user;
	 	curr_user = nullptr;

		update_users();

		//clears users
		for (int i = 0; i < users.size(); i++)
    		{
        	    delete users[i];
    		}
    		users.clear();

		read_users();
	    }
	}
	else if (choice == '3')
	{
	    if (login_admin())
	    {
		//loops admin interface until admin logs out
		while (curr_admin->initialize()) { }
		delete curr_admin;
		curr_admin = nullptr;
    	    }
	}
        else if (choice == '4')
	{
	    cout << "Goodbye!" << endl;
	    break;
	}	
    }
}

void Library::read_users()
{
    ifstream inFile;
    string username;
    string password;
    string debt;
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
	debt = temp;

	User* new_user = new User(username, password, stoi(debt), catalog);
	this->users.push_back(new_user);
    }
}

void Library::read_admins()
{
    ifstream inFile;
    string username;
    string password;
    string temp;

    inFile.open("admin_accounts.txt");
    if (!inFile.is_open())
    {
        cout << "admin_accounts.txt does not exist!" << endl;
    }

    while (getline(inFile, temp))
    {
        username = temp;
        getline(inFile, temp);
        password = temp;

        Admin* new_admin = new Admin(username, password);
        this->admins.push_back(new_admin);
    }
}

void Library::init_catalog()
{
    this->catalog = catalog->getInstance();
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
    cout << "2. User Login" << endl;
    cout << "3. Admin Login" << endl;
    cout << "4. Exit" << endl;
 
    /* User Input */ 
    while (choice != '1' && choice != '2' && choice != '3' && choice != '4')
    {	
 	cin >> choice;
  	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choice == '1')	
	{
	    create_acc();
	}
        else if (choice == '2' || choice == '3' || choice == '4')
	{
	    return choice;
	}
    	else if (choice != '1' && choice != '2' && choice != '3' && choice != '4')
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
    string debt = "0";

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
    outFile << debt << "\n";

    outFile.close();

    cout << "\nAccount " << username << " successfully created!" << endl;

    //adds new user to vector containing total users
    User* new_user = new User(username, password, stoi(debt), catalog); 
    this->users.push_back(new_user);
}

void Library::update_users()
{
    ofstream outFile;  //outputs to accounts.txt
    ifstream books;    //reads from borrowed_books.txt
    string username;   //username to check 
    string title;      //book title to read from books
    
    int debt_cnt;
    int count = 0;
    outFile.open("accounts.txt");
 
    cin.ignore(256, '\n');

    //counts each user's debt total 
    for (int i = 0; i < users.size(); i++)	
    {
	debt_cnt = 0;
	books.open("borrowed_books.txt");
	
	outFile << users.at(i)->get_username() << endl;
	outFile << users.at(i)->get_password() << endl;

	while (books >> username)
	{
	    //adds 5 to current user's total debt if it's a match
	    if (users.at(i)->get_username() == username)
	    {
	 	debt_cnt += 5;
	    }

  	    //reads and ignores book title	
	    getline(books, title);
	}

        outFile << to_string(debt_cnt) << endl; 

  	books.close(); 
    }

    outFile.close();
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
	    curr_user = new User(username, password, users.at(i)->get_debt(), catalog);

	    /* Outputs Welcome Message */
	    cout << "\nWelcome, " << username << "!" << endl;

	    return true;
	}
    }

    cout << "Wrong Username/Password!" << endl;

    return false;
}

bool Library::login_admin()
{
    ifstream inFile;
    string username;
    string password;

    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    for (int i = 0; i < admins.size(); i++)
    {
        if (username == admins.at(i)->get_username() &&
            password == admins.at(i)->get_password())
        {
	    //sets current admin information
	    curr_admin = new Admin(username, password);

	    // Outputs Welcome Message 
	    cout << "\nWelcome, " << username << "!" << endl;

            return true;
        }
    }

    cout << "Wrong Username/Password!" << endl;

    return false;
}





















