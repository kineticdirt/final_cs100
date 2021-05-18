#ifndef __Book__TEST__HPP
#define __Book__TEST__HPP

#include "gtest/gtest.h"
#include "../header/Book.hpp"
#include "../header/BookComponent.hpp"
#include "../header/BookGroup.hpp"
#include "../src/BookGroup.cpp"
#include <iostream>
using namespace std;

TEST(BookTest,ConstructorTest){
	stringstream out;
	Book* test = new Book("Hamlet","William Shakespeare");
	test->display(out);
	EXPECT_EQ(out.str(),"	Book: Hamlet by William Shakespeare\n");
}

TEST(BookTest,ConstructorTest_2){
	stringstream out;
	BookGroup* test = new BookGroup("love");
	test->display(out);
	EXPECT_EQ(out.str(),"Book Group: love\n\n");
}

TEST(BookTest,GenreTest){
	stringstream out;
	BookComponent* book = new Book("Hamlet","William Shakespeare");
	BookComponent* test = new BookGroup("love");
	test->Add(book); 
	test->display(out);
	EXPECT_EQ(out.str(),"Book Group: love\n\n\t\tBook: Hamlet by William Shakespeare\n\n");
}

TEST(BookTest,Sub_Genre_Test){
	stringstream out;
	BookComponent* book = new Book("Hamlet","William Shakespeare");
	BookComponent* sub_genre = new BookGroup("love");
	sub_genre->Add(book);
	BookComponent* test = new BookGroup("Drama"); 
	test->Add(sub_genre); 
	test->display(out);
	EXPECT_EQ(out.str(),"Book Group: Drama\n\n\tBook Group: love\n\n\t\tBook: Hamlet by William Shakespeare\n\n\n");
}


#endif
