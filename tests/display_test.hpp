#ifndef __DISPLAY__TEST__HPP
#define __DISPLAY__TEST__HPP

#include "gtest/gtest.h"
#include "../header/Book.hpp"
#include "../header/Catalog.hpp"
#include "../src/catalog.cpp"
#include "../header/display.hpp"
#include "../header/display_genre.hpp"
#include "../header/display_subgenre.hpp"
#include "../header/display_author.hpp"
#include "../header/display_title.hpp"
#include <iostream>
using namespace std;

TEST(DisplayTest,GenreTest){
	stringstream out;
	Catalog* c = c->getInstance();
	c->read_books();
	c->set_display(new Display_Genre("Novel"));
	c->print(out);
	//EXPECT_EQ(out.str(),"Genre: Novel\n\n");
	EXPECT_EQ(out.str(),"Genre: Novel\n\nBook: The Great Gatsby by F. Scott Fitzgerald\nBook: The Lord of the Rings by J.R.R. Tolkien\n");
}

TEST(DisplayTest,SubGenreTest){
	stringstream out;
	Catalog* d = d->getInstance();
	d->set_display(new Display_Subgenre("Horror"));
	d->print(out);
	EXPECT_EQ(out.str(),"SubGenre: Horror\n\nBook: The Raven by Edgar Allan Poe\n");
}

TEST(DisplayTest,AuthorTest){
	stringstream out;
	Catalog* e = e->getInstance();
	e->set_display(new Display_Author("None"));
	e->print(out);
	EXPECT_EQ(out.str(),"Author: None\n\nBook: Entertainment Weekly April 2020 by None\nBook: National Geographic September 2020 by None\n");
}

TEST(DisplayTest,TitleTest){
	stringstream out;
	Catalog* f = f->getInstance();
	f->set_display(new Display_Title("The Great Gatsby"));
	f->print(out);
	EXPECT_EQ(out.str(),"Title: The Great Gatsby\n\nBook: The Great Gatsby by F. Scott Fitzgerald\n");
}

#endif
