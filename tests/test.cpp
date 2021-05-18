#include "../tests/Book_test.hpp"
#include "gtest/gtest.h"
#include "../header/library.hpp"
#include "../header/user.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
