#ifndef __CATALOG__HPP___
#define __CATALOG__HPP___
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include "Book.hpp"
#include "display.hpp"

using namespace std;

class Catalog {
    vector<Book*> magazine;
    vector<Book*> comicBook;
    vector<Book*> poem;
    vector<Book*> novel;
    Display* display;
    static Catalog* instance;
    ~Catalog();

    protected:
	vector<vector<Book*>> books;

    public:
	Catalog();
	void set_display(Display* new_display);
        void print(ostream& out) const;
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
					if (genre == "Novel")
						novel.push_back(book);
					else if (genre == "Magazine")
						magazine.push_back(book);
					else if (genre == "Comic Book")
						comicBook.push_back(book);
					else if (genre == "Poem")
						poem.push_back(book);
            }
			bookList.close(); 
            books.push_back(novel);
            books.push_back(magazine);
            books.push_back(comicBook);
            books.push_back(poem);
        }

        void add_to_books(Book* new_book, bool overwriteCondition) {
            	ofstream writingBooks("writing_books.txt");
            	int ISBN_Line = std::stoi(new_book->getIsbn());
            	ISBN_Line = ISBN_Line * 5;
	    		ifstream bookList;
            	bookList.open ("books.txt");
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
		for(int i = 0; i < 5; i++){
			writingBooks << new_book->getname() << '\n';
			writingBooks << new_book->getauthor() << '\n';
			writingBooks << new_book->getIsbn() << '\n';
			writingBooks << new_book->getgenre() << '\n';
			writingBooks << new_book->getsubgenre() << '\n';
		}
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
