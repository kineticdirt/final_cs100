#include "gtest/gtest.h"
#include "../src/library.cpp"
#include "../src/BookGroup.cpp"
#include "../header/Book.hpp"
#include "../header/BookComponent.hpp"
#include "../header/BookGroup.hpp"
#include "../src/user.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
