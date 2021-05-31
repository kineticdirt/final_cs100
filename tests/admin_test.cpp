
#ifndef __ADMIN__TEST_HPP__
#define __ADMIN__TEST_HPP__

#include "gtest/gtest.h"
#include "../header/admin.hpp"
#include "../header/library.hpp"
#include "../header/admin.hpp"
#include "../header/Book.hpp"
#include "../header/BookComponent.hpp"
#include "../header/BookGroup.hpp"

TEST(AdminTest, UsernameTest) {
    Admin test = Admin("username", "password");
    EXPECT_EQ(test.get_username(), "username"); 
}

TEST(UserTest, PasswordTest) {
    Admin test = Admin("username", "password");
    EXPECT_EQ(test.get_password(), "password");
}

#endif //__ADMIN__TEST_HPP__
