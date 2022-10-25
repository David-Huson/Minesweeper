#include "../board.hpp"
#include "../cell.hpp"
#include "board-configurations.hpp"
#include "catch/catch.hpp"

TEST_CASE("Test initial board") {
  Board b;

  CHECK(!b.load("badFile.txt"));  // fail to load a non-existing file
  CHECK(b.load("test/four-by-four.in"));  // file opened successfully
  CHECK(NOTHING_CLICKED == b.str());  // original state of the board
}
