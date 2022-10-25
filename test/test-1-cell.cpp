#include "../cell.hpp"
#include "catch/catch.hpp"

TEST_CASE("Test cell with mine") {
  bool mine = true;
  Cell c(mine);

  CHECK(c.hasMine());
  CHECK(Cell::UNKNOWN == c.str());  // cell has not been uncovered yet

  c.toggleFlag();
  CHECK(Cell::FLAG == c.str());  // flagged

  bool clickResult = c.click();
  CHECK(!clickResult);  // cannot click a cell that has a flag on it

  c.toggleFlag();
  CHECK(Cell::UNKNOWN == c.str());  // flag is gong

  c.click();
  CHECK(Cell::MINE == c.str());  // mine can be clicked
}

TEST_CASE("Test cell without mine") {
  bool mine = false;
  Cell c(mine);

  CHECK(!c.hasMine());
  CHECK(Cell::UNKNOWN == c.str());  // cell has not been uncovered yet

  c.click();
  CHECK(Cell::NO_ADJACENT_MINES == c.str());  // no adjacent mine by default

  c.setAdjacentMineCount(6);  // set arbitrary number of adjacent mines
  CHECK("6" == c.str());  // show adjacent mine count

  bool clickResult = c.click();  // can't click to uncover a cell again
  CHECK(!clickResult);
}
