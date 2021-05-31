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
	user_menu();
    }
    
    return true;
}

void User::initialize_borrowed()
{
    ifstream inFile;
    string word;
    string title;

    inFile.open("borrowed_books.txt");
    if (!inFile.is_open())
    {
	cout << "borrowed_books.txt" << " does not exist!" << endl;
    } 

    while (inFile >> word)
    {
	//reads in book title
	if (word == this->username)
	{
	    getline(inFile, title); 
	    borrowed.push_back(title);
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

	if (choice == '1' || choice == '0' || choice == '3' || choice == '4' || choice == '5')
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

    cout << "1. View by genres" << endl;
    cout << "2. View by subgenres" << endl;

    cin >> choice;
 
    cin.ignore(256, '\n');
    if (choice == '1')
    {
	cout << "1. Novels" << endl;
	cout << "2. Magazines" << endl;
	cout << "3. Comic Books" << endl;
	cout << "4. Poems" << endl; 	
	cin >> choice;

	if (choice == '1')
	{
	    all_books->set_display(new Display_Genre("Novel"));
	}
	else if (choice == '2')
	{
	    all_books->set_display(new Display_Genre("Magazine"));
	}
	else if (choice == '3')
	{
	    all_books->set_display(new Display_Genre("Comic Book"));
	}
	else if (choice == '4')
	{
	    all_books->set_display(new Display_Genre("Poem"));
	}
	else
	{
	    cout << "Invalid choice!" << endl;
	    return;
	}
    }    
    else if (choice == '2')
    {
	cout << "1. Fiction" << endl;
	cout << "2. Fantasy" << endl;
	cout << "3. Non-Fiction" << endl;
	cout << "4. Educational" << endl;
	cout << "5. Science Fiction" << endl;
	cout << "6. Horror" << endl;	
	cin >> choice;

	if (choice == '1')
        {
            all_books->set_display(new Display_Subgenre("Fiction"));
        }
        else if (choice == '2')
        {
            all_books->set_display(new Display_Subgenre("Fantasy"));
        }
        else if (choice == '3')
        {
            all_books->set_display(new Display_Subgenre("Non-Fiction"));
        }
        else if (choice == '4')
        {
            all_books->set_display(new Display_Subgenre("Educational"));
        }
	else if (choice == '5')
	{
	    all_books->set_display(new Display_Subgenre("Science Fiction"));
	}
	else if (choice == '6')
	{
	    all_books->set_display(new Display_Subgenre("Horror"));
	}
	else
	{
	    cout << "Invalid choice!" << endl;
	    return;
	}
    }
    else
    {
        cout << "Invalid choice!" << endl;
	return;
    }

    all_books->print(out);
    cout << out.str() << endl;
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

void User::borrow_a_book()
{
    string book;
    cin.ignore(256, '\n');

    cout << "Enter title of book to borrow: ";
    getline(cin, book);

    borrowed.push_back(book); 
    debt += 5; 
    update_book_file();

    cout << "New book added to debt." << endl << endl;
}

void User::update_book_file()
{
    ofstream outFile;
    outFile.open("borrowed_books.txt", std::ios::app);

    //outputs newest borrowed book to outFile
    outFile << this->username << " " << borrowed.back() << endl;

    outFile.close();
}















