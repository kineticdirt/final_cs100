#ifndef __ADMIN__TEST_HPP__
#define __ADMIN__TEST_HPP__

#include "gtest/gtest.h"
#include "../header/admin.hpp"
#include "../header/library.hpp"
#include "../header/admin.hpp"
#include "../src/Admin.cpp"
#include "../header/Book.hpp"
#include <iostream>

TEST(AdminTest, UsernameTest) {
    Admin test = Admin("username", "password");
    EXPECT_EQ(test.get_username(), "username"); 
}
TEST(AdminTest, PasswordTest) {
    Admin test = Admin("username", "password");
    EXPECT_EQ(test.get_password(), "password");
}
TEST(AdminTest, DISABLED_BookTest) {
    Admin test = Admin("username", "password");
    test.borrow_user_book("password", "wholesome" , "delete_this");
    ifstream inputFile("borrowed_books.txt");
    string s1 = "";
    while(inputFile >> s1);
    EXPECT_EQ(s1, "delete_this");
}
#endif //__ADMIN__TEST_HPP__
