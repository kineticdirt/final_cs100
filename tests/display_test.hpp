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
		Catalog* c;
		c->read_books();
		c->set_display(new Display_Genre("MAGAZINE"));
		c->print(out);
		EXPECT_EQ(out.str(),"Genre: MAGAZINE\n\nBook: Entertainment Weekly April 2020 by None\nBook: National Geographic September 2020 by None");
}

TEST(DisplayTest,SubGenreTest){
		stringstream out;
		Catalog* c;
		c->read_books();
		c->set_display(new Display_Subgenre("Science Fiction"));
		c->print(out);
		EXPECT_EQ(out.str(),"SubGenre: Science Fiction\n\nBook: V for Vendetta by Alan Moore\nBook: East of West by Jonathan Hickman");
}

TEST(DisplayTest,AuthorTest){
		stringstream out;
		Catalog* c;
		c->read_books();
		c->set_display(new Display_Author("J.R.R. TOLKIEN"));
		c->print(out);
		EXPECT_EQ(out.str(),"Author: J.R.R. TOLKIEN\n\nBook: The Lord of the Rings by J.R.R. Tolkien");
}

TEST(DisplayTest,TitleTest){
		stringstream out;
		Catalog* c;
		c->read_books();
		c->set_display(new Display_Title("The Great Gatsby"));
		c->print(out);
		EXPECT_EQ(out.str(),"Title: The Great Gatsby\n\nBook: The Great Gatsby by F. Scott Fitzgerald");
}

#endif
