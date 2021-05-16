#include "../header/library.hpp"

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

        if (choice == '1')
    	{
	    create_acc();
    	}
        else if (choice == '2' || choice == '3')
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
    
    cin.ignore();
 
    cout << "Enter a username: ";
    getline(cin, username);
    cout << "Enter a password: ";
    getline(cin, password);
    
    outFile << username << "\n";
    outFile << password << "\n";
    outFile << "User \n\n";

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
    cin.ignore();

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






















