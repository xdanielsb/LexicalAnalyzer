#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "src/core.hpp"

TEST_CASE("testing the keywords") {
  CHECK(isKeyWord("struct") == true);
  CHECK(isKeyWord("another") == false);
  CHECK(isKeyWord("fn") == true);
  CHECK(isKeyWord("let") == true);
}

TEST_CASE("testing operators"){
  CHECK(isOperator("&") == true);
  CHECK(isOperator("++") == true);
  CHECK(isOperator("++/") == false);
}

TEST_CASE("testing isString"){
  CHECK(isString("\"str\"") == true);
  CHECK(isString("\"hello str") == false);
}

TEST_CASE("testing isNumber"){
  CHECK(isNumber("1223272932") == true);
  CHECK(isNumber("12") == true);
  CHECK(isNumber("12x") == false);
  CHECK(isNumber("01_") == false);
  CHECK(isNumber(" ") == false);
}

