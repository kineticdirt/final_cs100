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
	Search* search;
        
        static Catalog* instance;
        std::string catalogFile = "books.txt";
protected:
	vector<Book*> books;

public:
	Catalog();
	~Catalog();
	void set_display(Display* new_display);
        void print(ostream& out) const;
	void set_search(Search* new_search);
        Book* getbook();

        void setBooksFile(const std::string& filename=std::string("books.txt")) {
		catalogFile = filename;        	
        }


        void read_books() {
		ifstream bookList;
		Book* book;           //Book object to instantiate from books.txt
		string title;
		string author;
		string isbn;
		string genre;
		string subgenre;
		string temp;          //line to be read from books.txt

		bookList.open(catalogFile);
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
	void remove_to_books(string title, string author) {	
		remove("rwriting_books.txt");
		ofstream writingBooks("rwriting_books.txt");
	    	ifstream bookList;
            	bookList.open(catalogFile);
            	if(!bookList.is_open()){
                	cout << "File opening error!" << endl;
            	}
            	int index = 0;
		string temp_author = "";
		string line;
            	while (!bookList.eof()) {
                	getline(bookList, line, '\n');
			if(line == title) {
				getline(bookList, temp_author, '\n');
				if(temp_author == author) {
					getline(bookList, line, '\n');
					getline(bookList, line, '\n');
					getline(bookList, line, '\n');
				} else { 
					writingBooks << line << '\n';	
					writingBooks << temp_author << '\n';
				}
			} else {
				writingBooks << line << '\n';	
			}
		}
		bookList.close();
		writingBooks.close();
#if 1
		if(remove(catalogFile.c_str()) != 0){
			cout << "Failed to create " << catalogFile << "\n";
		} else {
			rename("rwriting_books.txt" , catalogFile.c_str());
		}
#endif
	}

        void add_to_books(Book* new_book, bool overwriteCondition) {
		remove("writing_books.txt");
            	ofstream writingBooks("writing_books.txt");
            	int ISBN_Line = stoi(new_book->getIsbn());
	    	ifstream bookList;
            	bookList.open(catalogFile);
            	if(!bookList.is_open()){
                	cout << "File opening error! " << catalogFile << endl;
            	}
            	int index = 0;
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
#if 1
		if(remove(catalogFile.c_str()) != 0){
			cout << "Failed to create " << catalogFile << "\n";
		} else {
			rename("writing_books.txt" , catalogFile.c_str());
		}
#endif
        
	}
 static Catalog* getInstance() { 
            if (!instance)
                instance = new Catalog();

            return instance; 
        }
        
};

#endif // !__CATALOG__HPP___
