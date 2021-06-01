#ifndef __USER__TEST_HPP__
#define __USER__TEST_HPP__

#include "gtest/gtest.h"
#include "../header/user.hpp"
#include "../header/library.hpp"
#include "../header/Catalog.hpp"
#include "../src/user.cpp"
#include <sstream>

TEST(UserTest, UsernameTest) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser", "FakePass", 0, catalog);

    EXPECT_EQ(test.get_username(), "FakeUser"); 
	delete catalog;
}

TEST(UserTest, PasswordTest) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser", "FakePass", 0, catalog);

    EXPECT_EQ(test.get_password(), "FakePass");
	delete catalog;
}

TEST(UserTest, DebtTest) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser", "FakePass", 25, catalog);

    EXPECT_EQ(test.get_debt(), 25);
	delete catalog;
}

TEST(UserTest, DebtAccumulation) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser", "FakePass", 0, catalog);

    istringstream in("The Great Gatsby"); 
    test.borrow_title(in);
    istringstream in2("The Raven");
    test.borrow_title(in2);
    EXPECT_EQ(test.get_debt(), 10);
	delete catalog;
}

TEST(UserTest, BorrowTitle) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser2", "FakePass2", 0, catalog);

    istringstream in("The Lord of the Rings");
    test.borrow_title(in);
    istringstream in2("The Raven");
    test.borrow_title(in2);

    testing::internal::CaptureStdout();
    test.view_borrowed();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("FakeUser2's borrowed books: \n\tThe Lord of the Rings\n\tThe Raven\n\n", output);
	delete catalog;
}

TEST(UserTest, BorrowInvalidTitle) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser3", "FakePass3", 0, catalog);

    istringstream in("Invalid Book");
    test.borrow_title(in);

    testing::internal::CaptureStdout();
    test.view_borrowed();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("FakeUser3's borrowed books: \n\n", output);
	delete catalog;
}

TEST(UserTest, BorrowAuthor) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser4", "FakePass4", 0, catalog);

    istringstream in("Alan Moore");
    test.borrow_author(in);

    testing::internal::CaptureStdout();
    test.view_borrowed();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("FakeUser4's borrowed books: \n\tV for Vendetta\n\n", output);
	delete catalog;
}

TEST(UserTest, BorrowInvalidAuthor) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser5", "FakePass5", 0, catalog);

    istringstream in("Invalid Title");
    test.borrow_author(in);

    testing::internal::CaptureStdout();
    test.view_borrowed();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("FakeUser5's borrowed books: \n\n", output);
	delete catalog;
}

TEST(UserTest, BorrowISBN) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser6", "FakePass6", 0, catalog);

    istringstream in("35");
    test.borrow_isbn(in);

    testing::internal::CaptureStdout();
    test.view_borrowed();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("FakeUser6's borrowed books: \n\tStopping by Woods on a Snowy Evening\n\n", output);
	delete catalog;
}

TEST(UserTest, BorrowInvalidISBN) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser7", "FakePass7", 0, catalog);

    istringstream in("Invalid ISBN");
    test.borrow_isbn(in);

    testing::internal::CaptureStdout();
    test.view_borrowed();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("FakeUser7's borrowed books: \n\n", output);
	delete catalog;
}

#endif //__USER__TEST_HPP__










