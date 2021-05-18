#ifndef __USER__TEST_HPP__
#define __USER__TEST_HPP__

#include "gtest/gtest.h"
#include "../header/user.hpp"
#include "../header/library.hpp"
#include "../src/user.cpp"
#include "../header/Book.hpp"
#include "../header/BookComponent.hpp"
#include "../header/BookGroup.hpp"

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

#endif //__USER__TEST_HPP__
