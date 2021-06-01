#ifndef __CATALOG__HPP___
#define __CATALOG__HPP___
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include "Book.hpp"
#include "display.hpp"
#include "search.hpp"
#include <string>

using namespace std;

class Display;
class Search;

class Catalog {
private:
        Display* display;
	Search* s;
        
        static Catalog* instance;	
protected:
	vector<Book*> books;

public:
	Catalog();
	~Catalog();
	void set_display(Display* new_display);
        void print(ostream& out) const;
	void set_search(Search* new_search);
        Book* getbook();
        void read_books() {
		ifstream bookList;
		Book* book;           //Book object to instantiate from books.txt
		string title;
		string author;
		string isbn;
		string genre;
		string subgenre;
		string temp;          //line to be read from books.txt

		bookList.open("books.txt");
		if(!bookList.is_open()) {
			cout << "File opening error!" << endl;
		}

		while (getline(bookList, temp)) {
		//reads a book's information
			title = temp;
			getline(bookList, temp);
			author = temp;
			getline(bookList, temp);
			isbn = temp;
			getline(bookList, temp);
			genre = temp;
			getline(bookList, temp);
			subgenre = temp;

			//instantiates book 
			book = new Book(title, author, isbn, genre, subgenre);

			//adds books to their respective vector of genre
			
			books.push_back(book);
            }
	    bookList.close(); 
        }

        void add_to_books(Book* new_book, bool overwriteCondition) {
            	ofstream writingBooks("writing_books.txt");
            	int ISBN_Line = stoi(new_book->getIsbn());
	    	ifstream bookList;
            	bookList.open("books.txt");
				//checking if the file is open
            	if(!bookList.is_open()){
                	cout << "File opening error!" << endl;
            	}
            		int index = 0;
			//indexing throughout the file
			string line = "";
            	while (index != ISBN_Line) {
                	getline(bookList, line, '\n');
			writingBooks << line << '\n';
			index++; 
			}
			getline(bookList, line, '\n'); 
			writingBooks << new_book->getname() << '\n';
			getline(bookList, line, '\n');
			writingBooks << new_book->getauthor() << '\n';
			getline(bookList, line, '\n');
			writingBooks << new_book->getIsbn() << '\n';
			getline(bookList, line, '\n');
			writingBooks << new_book->getgenre() << '\n';
			getline(bookList, line, '\n');
			writingBooks << new_book->getsubgenre() << '\n';
		
		while (!bookList.eof()) {
                	getline(bookList, line, '\n');
			writingBooks << line << '\n';
		} 
		bookList.close();
		writingBooks.close();
		if(remove("books.txt") != 0){
			rename("writing_books.txt" , "books.txt");	
		} else {
			cout << "Failed to create book.txt";
		}
        
	}
 static Catalog* getInstance() { 
            if (!instance)
                instance = new Catalog();

            return instance; 
        }
        
};

#endif // !__CATALOG__HPP___
