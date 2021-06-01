#ifndef __CATALOG__TEST__HPP
#define __CATALOG__TEST__HPP

#include "gtest/gtest.h"
#include "../header/Book.hpp"
#include "../header/Catalog.hpp"
#include "../header/display.hpp"
#include <iostream>
#include <string>
#include<stdlib.h>
using namespace std;


TEST(CatalogTest, addingTest){
        system("cp books.txt books_test.txt");
	stringstream out;
	Catalog* c = c->getInstance();
        c->setBooksFile("books_test.txt");
	string Isbn = "20";
	Book* book1 = new Book("testing", "librarian", Isbn, "Poem", "Horror");
	c->add_to_books(book1, true);
	string temp;
	ifstream checker("books_test.txt");
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
		getline(checker, temp);
		getline(checker, temp);
		if(book1->getname() == title && book1->getauthor() == author) {
			success = true;
		}
	}
					
	ASSERT_TRUE( success);	
	
        remove("books_test.txt");
}

TEST(CatalogTest, deleteTest) {
        system("cp books.txt books_test.txt");
	stringstream out;
	Catalog* c = c->getInstance();
        c->setBooksFile("books_test.txt");
	string Isbn = "20";
	Book* book1 = new Book("testing", "librarian", Isbn, "Poem", "Horror");
	c->add_to_books(book1, true);
	c->remove_to_books("testing", "librarian");
	string temp;
	ifstream checker("books_test.txt");
	string title;
	string author;
		
	bool success = true;
	while (getline(checker, temp)) {
		title = temp;
		getline(checker, temp);
		author = temp;
		getline(checker, temp);
		getline(checker, temp);
		getline(checker, temp);
		if(book1->getname() == title && book1->getauthor() == author) {
			success = false;
		}
	}

	ASSERT_TRUE( success);	
        remove("books_test.txt");
}

#endif		
