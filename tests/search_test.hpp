#ifndef __SEARCH__TEST__HPP
#define __SEARCH__TEST__HPP

#include "gtest/gtest.h"
#include "../header/Book.hpp"
#include "../header/Catalog.hpp"
#include "../src/catalog.cpp"
#include "../header/search.hpp"
#include "../header/search_isbn.hpp"
#include "../header/search_author.hpp"
#include "../header/search_title.hpp"
#include <iostream>
using namespace std;

TEST(SearchTest, authorTest){
	Catalog* c = c->getInstance();
	auto search = new Search_Author("F. Scott Fitzgerald");
	c->set_search(search);
	Book* test = c->getbook();
        ASSERT_TRUE(test != nullptr);
	EXPECT_EQ(test->getname(),"The Great Gatsby");
}

TEST(SearchTest, isbnTest){
	Catalog* c = c->getInstance();
	c->set_search(new Search_ISBN("30"));
	Book* test = c->getbook();
        ASSERT_TRUE(test != nullptr);
	EXPECT_EQ(test->getname(),"The Raven");
}

TEST(SearchTest, titleTest){
	Catalog* c = c->getInstance();
	c->set_search(new Search_Title("National Geographic September 2020"));
	Book* test = c->getbook();
        ASSERT_TRUE(test != nullptr);
	EXPECT_EQ(test->getIsbn(),"15");
}

TEST(SearchTest, titleTest_2){
	Catalog* c = c->getInstance();
	c->set_search(new Search_Title("National Geographic September 2020"));
	Book* test = c->getbook();
        ASSERT_TRUE(test != nullptr);
	EXPECT_EQ(test->getauthor(),"None");
}

TEST(SearchTest, title_nulltest){
        Catalog* c = c->getInstance();
        c->set_search(new Search_Title("AA"));
        Book* test = c->getbook();
        ASSERT_TRUE(test == nullptr);
}

TEST(SearchTest, isbn__nulltest){
        Catalog* c = c->getInstance();
        c->set_search(new Search_ISBN("100"));
        Book* test = c->getbook();
        ASSERT_TRUE(test == nullptr);
}

TEST(SearchTest, author_nulltest){
        Catalog* c = c->getInstance();
        c->set_search(new Search_Author("AA"));
        Book* test = c->getbook();
        ASSERT_TRUE(test == nullptr);
}


#endif
