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

#endif //__USER__TEST_HPP__
