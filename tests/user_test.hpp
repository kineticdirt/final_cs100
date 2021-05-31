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
}

TEST(UserTest, PasswordTest) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser", "FakePass", 0, catalog);

    EXPECT_EQ(test.get_password(), "FakePass");
}

TEST(UserTest, DebtTest) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser", "FakePass", 25, catalog);

    EXPECT_EQ(test.get_debt(), 25);
}

TEST(UserTest, DebtAccumulation) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser", "FakePass", 0, catalog);

    istringstream in("Test_Book"); 
    test.borrow_a_book(in);
    EXPECT_EQ(test.get_debt(), 5);
}

TEST(UserTest, BorrowMultipleBooks) {
    Catalog* catalog = catalog->getInstance();
    User test = User("FakeUser2", "FakePass2", 0, catalog);

    istringstream in("Test_Book_1");
    test.borrow_a_book(in);
    istringstream in2("Test_Book_2");
    test.borrow_a_book(in2);
    istringstream in3("Test_Book_3");
    test.borrow_a_book(in3);

    testing::internal::CaptureStdout();
    test.view_borrowed();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("FakeUser2's borrowed books: \n\tTest_Book_1\n\tTest_Book_2\n\tTest_Book_3\n\n", output);
}

#endif //__USER__TEST_HPP__










