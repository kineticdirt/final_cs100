#ifndef __USER__TEST_HPP__
#define __USER__TEST_HPP__

#include "gtest/gtest.h"
#include "../header/user.hpp"
#include "../header/library.hpp"
#include "../src/user.cpp"
#include "../header/Book.hpp"


TEST(UserTest, UsernameTest) {
    BookComponent* book = new Book("TestBook", "Test Author");
    
    User test = User("username", "password", book);

    EXPECT_EQ(test.get_username(), "username"); 
}

TEST(UserTest, PasswordTest) {
    BookComponent* book = new Book("TestBook", "Test Author");

    User test = User("username", "password", book);

    EXPECT_EQ(test.get_password(), "password");
}

TEST(UserTest, ViewBooksTest) {
    stringstream out;

    BookComponent* book1 = new Book("Hamlet", "William Shakespeare"); 
    BookComponent* book2 = new Book("Twilight" , "Stephanie Myers");
    BookComponent* book3 = new Book("The Crucible", "Arthur Miller");
    BookComponent* sub_genre = new BookGroup("Romance");

    sub_genre->Add(book1);
    sub_genre->Add(book2);

    BookComponent* test_book = new BookGroup("Drama");

    test_book->Add(book3);
    test_book->Add(sub_genre);

    User test = User("username", "password", test_book);

    test.view_books(out);
    EXPECT_EQ(out.str(), "Book Group: Drama\n\n\t\tBook: The Crucible by Arthur Miller\n\n\tBook Group: Romance\n\n\t\tBook: Hamlet by William Shakespeare\n\n\t\tBook: Twilight by Stephanie Myers\n\n\n");
}

#endif //__USER__TEST_HPP__
