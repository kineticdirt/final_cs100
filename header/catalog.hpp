#ifndef __CATALOG__HPP___
#define __CATALOG__HPP___
#include <vector>
#include <fstream>
#include <iostream>
#include "Book.hpp"
#include "display.hpp"
using namespace std;

class Display;

class Catalog {
    private:
        vector<Book*> magazine;
        vector<Book*> comicBook;
        vector<Book*> poem;
        vector<Book*> novel;
        Display* display;
        Catalog();
        static Catalog* instance;
        
protected:
    vector<vector<Book*>> books;

    public:
        ~Catalog();
        void set_display(Display* new_display);
        void print(ostream& out) const;
        void read_books() {
            ifstream bookList;
            Book* book;           
            string title;
            string author;
            string isbn;
            string genre;
            string subgenre;
            string temp;          

            bookList.open("books.txt");
            if(!bookList.is_open()) {
                cout << "File opening error!" << endl;
            }
            
            while (getline(bookList, temp)) {
                
                title = temp;
                getline(bookList, temp);
                author = temp;
                getline(bookList, temp);
                isbn = temp;
                getline(bookList, temp);
                genre = temp;
                getline(bookList, temp);
                subgenre = temp;

                 
                book = new Book(title, author, isbn, genre, subgenre);

               
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
        
        static Catalog* getInstance() { 
            if (!instance)
                instance = new Catalog();

            return instance; 
        }


};


#endif // !__CATALOG__HPP___

