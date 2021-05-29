#ifndef __CATALOG__HPP___
#define __CATALOG__HPP___
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include "Book.hpp"
using namespace std;

class Catalog {
    private:
        Catalog() {}
protected:
    vector<Book*> magazine;
    vector<Book*> comicBook;
    vector<Book*> poem;
    vector<Book*>novel;
    static Catalog* instance;
    public:
        static void read_books() {
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

        }

        static void output_to_books(Book* new_book) {
            ofstream bookList("writing_books.txt");
            int ISBN_Line = std::stoi(new_book.getIsbn());
            ISBN_Line = ISBN_Line * 5;
            bookList.open ("books.txt");
	
            if(!bookList.is_open()){
                cout << "File opening error!" << endl;
            }
            int index = 0;
            while (index != ISBN_Line) {
                
            }
        }
        
        static Catalog* getInstance() { 
            if (!instance)
                instance = new Catalog();

            return instance; 
        }
};


#endif // !__CATALOG__HPP___
