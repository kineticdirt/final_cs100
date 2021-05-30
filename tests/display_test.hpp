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
		Catalog c;
		c.read_books();
		c.set_display(new Display_Genre("Novel"));
		c.print(out);
		EXPECT_EQ(out.str(),"Genre: Novel\n\nBook: The Great Gatsby by F. Scott Fitzgerald\nBook: The Lord of the Rings by J.R.R. Tolkien\n");
}

TEST(DisplayTest,SubGenreTest){
		stringstream out;
		Catalog c;
		c.read_books();
		c.set_display(new Display_Subgenre("Horror"));
		c.print(out);
		EXPECT_EQ(out.str(),"SubGenre: Horror\n\nBook: The Raven by Edgar Allan Poe\n");
}

TEST(DisplayTest,AuthorTest){
		stringstream out;
		Catalog c;
		c.read_books();
		c.set_display(new Display_Author("None"));
		c.print(out);
		EXPECT_EQ(out.str(),"Author: None\n\nBook: Entertainment Weekly April 2020 by None\nBook: National Geographic September 2020 by None\n");
}

TEST(DisplayTest,TitleTest){
		stringstream out;
		Catalog c;
		c.read_books();
		c.set_display(new Display_Title("The Great Gatsby"));
		c.print(out);
		EXPECT_EQ(out.str(),"Title: The Great Gatsby\n\nBook: The Great Gatsby by F. Scott Fitzgerald\n");
}

#endif
