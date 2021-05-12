#ifndef __Book__TEST__HPP
#define __Book__TEST__HPP

#include "gtest/gtest.h"
#include "../Book.hpp"
#include "../Book.cpp"
#include <iostream>
using namespace std;

TEST(BookTest,ConstructorTest){
	stringstream out;
	Book* test = new Book("12345","Hamlet","William Shakespeare");
	test->print(out);
	EXPECT_EQ(out.str(),"ISBN: 12345\nName: Hamlet\nAuthor: William Shakespeare\n");
}

TEST(BookTest,ISBNTest){
	Book* test = new Book("12345","Hamlet","William Shakespeare");
	EXPECT_EQ(test->GetISBN(), "12345");
}

TEST(BookTest,NameTest){
	Book* test = new Book("12345","Hamlet","William Shakespeare");
	EXPECT_EQ(test->Getname(), "Hamlet");
}

TEST(BookTest,AuthorTest){
	Book* test = new Book("12345","Hamlet","William Shakespeare");
	EXPECT_EQ(test->Getauthor(), "William Shakespeare");
}

#endif
