#ifndef __CATALOG__TEST__HPP
#define __CATALOG__TEST__HPP

#include "gtest/gtest.h"
#include "../header/Book.hpp"
#include "../header/Catalog.hpp"
#include "../header/display.hpp"
#include <iostream>
#include <string>
using namespace std;


TEST(CatalogTest, addingTest){
		stringstream out;
		Catalog* c = c->getInstance();
		string Isbn = "20";
		Book* book1 = new Book("testng", "librarian", Isbn, "Poem", "Horror");
		bool bool1 = true;
		c->add_to_books(book1, bool1);
		string temp;
		ifstream checker("books.txt");
		Book* book;
		string title;
		string author;
		string isbn;
		string genre;
		string subgenre;
		
		bool success = false;
		while (getline(checker, temp)) {
			title = temp;
			getline(checker, temp);
			author = temp;
			getline(checker, temp);
			isbn = temp;
			getline(checker, temp);
			genre = temp;
			getline(checker, temp);
			subgenre = temp;
			book = new Book(title, author, isbn, genre, subgenre);
			if(book1->getname() == book->getname() && book1->getIsbn() == book->getIsbn() && book1->getauthor() == book->getauthor() && book1->getsubgenre() == book->getsubgenre() && book1->getgenre() == book->getgenre()) {
				success = true;
			}
		}
						
		ASSERT_TRUE( success);	
		
}

#endif		
