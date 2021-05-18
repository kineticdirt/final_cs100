#include "../header/library.hpp"

Library::Library()
{
    acc_file_name = "accounts.txt";
}

Library::Library(string acc_file_name)
{
    this->acc_file_name = acc_file_name;
}

void Library::menu()
{
    char choice = ' ';
    
    cout << endl;
    cout << "========================" << endl;    
    cout << "------Library Menu------" << endl;
    cout << "========================" << endl;

    cout << "1. Create Account" << endl;
    cout << "2. Login" << endl;
  
    while (choice != '1' && choice != '2')
    {
	cin >> choice;

        if (choice == '1')
    	{
	    create_acc();
    	}
    	else if (choice == '2')
    	{	
	    login();
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
        menu();
    } 

    while (!inFile.eof())
    {
 	getline(inFile, read_user);
       	getline(inFile, read_pass);
        getline(inFile, read_admin);

	//cout << "Read " << read_user << ", " << read_pass << ", " << read_admin << endl;

  	if (read_user == username && read_pass == password)
	{
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
	menu();
    }

    inFile.close();
}






















