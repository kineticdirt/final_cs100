#include "../header/user.hpp"

User::User(string username, string password, int debt, Catalog* books)
{
    this->username = username;
    this->password = password;
    this->debt = debt;
    this->all_books = books;
    initialize_borrowed();
}

User::~User()
{

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
    else if (choice == '2')
    {
	borrow_menu();
    }
    else if (choice == '3')
    {
	view_debt();
    }
    else if (choice == '4')
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
    cout << "2. Borrow A Book" << endl;
    cout << "3. View Debt" << endl;
    cout << "4. View Borrowed Books" << endl;
    cout << "0. Main Menu" << endl;

    /* User Input */
    cin >> choice;
    if (choice == '0' || choice == '1' || choice == '2' || choice == '3' || choice == '4')
    {
	return choice;
    }
    else
    {
	cout << "Enter a valid menu option!" << endl;
	return ' ';
    }
}

void User::borrow_menu()
{
    char choice;

    cout << endl << endl;
    cout << "1. Borrow a book by title" << endl;
    cout << "2. Borrow a book by author" << endl;
    cout << "3. Borrow a book by isbn" << endl;

    cin >> choice;
    cin.ignore(256, '\n');

    if (choice == '1')
    {
	borrow_title(cin);
    }
    else if (choice == '2')
    {
	borrow_author(cin);
    }
    else if (choice == '3')
    {
	borrow_isbn(cin);
    }
    else 
    {
	cout << "Invalid option!" << endl;
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
    string title;
    string author;
    char choice;

    cout << "1. View by genres" << endl;
    cout << "2. View by subgenres" << endl;
    cout << "3. View by title" << endl;
    cout << "4. View by author" << endl;

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
    else if (choice == '3')
    {
	cout << "Enter title to display: ";
	getline(cin, title);

	all_books->set_search(new Search_Title(title));
	Book* target = all_books->getbook();

	if (target != nullptr)
	{
	    all_books->set_display(new Display_Title(title));
	}
	else
	{
	    cout << "Title doesn't exist!" << endl;
	    return;
	}
    }
    else if (choice == '4')
    {
	cout << "Enter author to display: ";
	getline(cin, author);

	all_books->set_search(new Search_Author(author));
	Book* target = all_books->getbook();

	if (all_books->getbook() != nullptr)
	{
	    all_books->set_display(new Display_Author(author));
	}
	else
	{
	    cout << "Author doesn't exist!" << endl;
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

void User::borrow_title(istream& in)
{
    string book;

    cout << "Enter title of book to borrow: ";
    getline(in, book);

    all_books->set_search(new Search_Title(book));
    Book* target = all_books->getbook();

    //only adds a book if the book exists in Catalog
    if (target != nullptr)
    { 
	borrowed.push_back(book); 
        debt += 5; 
        update_book_file();
	cout << "Successfully borrowed " << book << "." << endl;
	cout << "New book added to debt." << endl << endl;
    }
    else
    {
	cout << book << " doesn't exist in our catalog!" << endl;
    }
}

void User::borrow_author(istream& in)
{
    string author;

    cout << "Enter author to borrow: ";
    getline(in, author);

    all_books->set_search(new Search_Author(author));
    Book* target = all_books->getbook();

    //only adds a book if the author exists in Catalog
    if (target != nullptr)
    {
        borrowed.push_back(target->getname());
        debt += 5;
        update_book_file();
	cout << "Successfully borrowed " << target->getname() << "." << endl;
        cout << "New book added to debt." << endl << endl;
    }
    else
    {
        cout << author << " doesn't exist in our catalog!" << endl;
    }
}

void User::borrow_isbn(istream& in)
{
    string isbn;

    cout << "Enter ISBN of book to borrow: ";
    getline(in, isbn);

    all_books->set_search(new Search_ISBN(isbn));
    Book* target = all_books->getbook();

    //only adds a book if the ISBN exists in Catalog
    if (target != nullptr)
    {
        borrowed.push_back(target->getname());
        debt += 5;
        update_book_file();
	cout << "Successfully borrowed " << target->getname() << "." << endl;
        cout << "New book added to debt." << endl << endl;
    }
    else
    {
        cout << "ISBN " << isbn << " doesn't exist in our catalog!" << endl;
    }
}

void User::update_book_file()
{
    ofstream outFile;
    outFile.open("borrowed_books.txt", std::ios::app);

    //outputs newest borrowed book to outFile
    outFile << this->username << " " << borrowed.back() << endl;

    outFile.close();
}















