#include "Book_test.hpp"
#include "display_test.hpp"
#include "user_test.hpp"
#include "gtest/gtest.h"
#include "search_test.hpp"
#include "admin_test.hpp"
#include "catalog_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
