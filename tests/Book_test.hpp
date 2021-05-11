#ifndef __Book__TEST__HPP
#define __Book__TEST__HPP

#include "gtest/gtest.h"
#include "../Book.cpp"
#include "../Book.hpp"
#include <iostream>
using namespace std;

TEST(BookTest,ConstructorTest){
	stringstream out;
	Book* test = new Book(new BookNode({1521,"Hamlet","William Shakespeare","Drama"}));
	test->print(out);
	EXPECT_EQ(out.str(),"ISBN: 1521\nName: Hamlet\nAuthor: William Shakespeare\nGenre: Drama\n");
}

TEST(BookTest,ISBNTest){
	Book* test = new Book(new BookNode({1521,"Hamlet","William Shakespeare","Drama"}));
	EXPECT_EQ(test->GetISBN(), "1521");
}

TEST(BookTest,NameTest){
	Book* test = new Book(new BookNode({1521,"Hamlet","William Shakespeare","Drama"}));
	EXPECT_EQ(test->Getname(), "Hamlet");
}

TEST(BookTest,AuthorTest){
	Book* test = new Book(new BookNode({1521,"Hamlet","William Shakespeare","Drama"}));
	EXPECT_EQ(test->Getauthor(), "William Shakespeare");
}

TEST(BookTest,GenreTest){
	Book* test = new Book(new BookNode({1521,"Hamlet","William Shakespeare","Drama"}));
	EXPECT_EQ(test->Getgenre(), "Drama");
}

#endif
