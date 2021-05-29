#ifndef __Book__TEST__HPP
#define __Book__TEST__HPP

#include "gtest/gtest.h"
#include "../header/Book.hpp"
#include <iostream>
using namespace std;

TEST(BookTest,NameTest){
		stringstream out;
		Book* test = new Book("Hamlet","William Shakespeare","11041","Drama");
		EXPECT_EQ(test->getname(),"Hamlet");
}

TEST(BookTest,AutjorTest){
		stringstream out;
		Book* test = new Book("Hamlet","William Shakespeare","11041","Drama");
		EXPECT_EQ(test->getauthor(),"William Shakespeare");
}

TEST(BookTest,isbnTest){
		stringstream out;
		Book* test = new Book("Hamlet","William Shakespeare","11041","Drama");
		EXPECT_EQ(test->getIsbn(),"11041");
}

TEST(BookTest,genreTest){
		stringstream out;
		Book* test = new Book("Hamlet","William Shakespeare","11041","Drama");
		EXPECT_EQ(test->getsubgenre(),"Drama");
}
#endif
