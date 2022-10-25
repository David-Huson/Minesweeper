#include <sstream>

#include "../board.hpp"
#include "board-configurations.hpp"
#include "catch/catch.hpp"

TEST_CASE("Board Game Play") {
  Board b;
  CHECK(b.load("test/four-by-four.in"));  // successful file load

  SECTION("Invalid move to click out-of-boundary cells") {
    CHECK(!b.click(-1, 0));
    CHECK(!b.click(4, 0));
    CHECK(!b.click(0, -1));
    CHECK(!b.click(0, 4));
  }

  SECTION("Clicking on flagged cell") {
    CHECK(b.flag(0, 0));
    CHECK(!b.click(0, 0));  // call not click a flagged cell
    CHECK(b.flag(0, 0));  // toggle successfully at cell 0 0
    CHECK(b.click(0, 0));  // clicking cell successfully
    CHECK(TOP_LEFT_CLICKED == b.str());
  }

  SECTION("Clicking to reveal more") {
    b.click(0, 0);
    b.click(3, 2);
    CHECK(BOTTOM_RIGHT_NUMBER_CLICKED == b.str());

    b.click(0, 3);
    CHECK(TOP_ROW_ALL_CLICKED == b.str());
  }
}
