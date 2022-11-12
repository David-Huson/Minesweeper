
#include "../text-menu-app.hpp"
#include "board-configurations.hpp"
#include "catch/catch.hpp"

TEST_CASE("Text Menu App class") {
  // test get file name
  TextMenuApp app;

  CHECK(!app.gameIsOver());

  CHECK("Please enter a file name with the minefield information: " == app.getPrompt());

  // file loading
  CHECK(!app.load("foo.bar.baz")); // file does not exist
  CHECK("Please enter a file name with the minefield information: " == app.getPrompt());
  CHECK(app.load("test/four-by-four.in"));  // load correct file

  // initial state
  CHECK(NOTHING_CLICKED +
            "Choose your next move(c or f) and cell, e.g. c 0 3 to click row "
            "zero column 3: " ==
        app.getPrompt());

  // invalid moves
  CHECK(!app.move('z', 0, 0));
  CHECK("Invalid move. Please enter your next move: " == app.getPrompt());
  CHECK(!app.move('C', -1, 0));
  CHECK("Invalid move. Please enter your next move: " == app.getPrompt());
  CHECK(!app.move('c', 0, -1));
  CHECK("Invalid move. Please enter your next move: " == app.getPrompt());
  CHECK(!app.move('F', 4, 0));
  CHECK("Invalid move. Please enter your next move: " == app.getPrompt());
  CHECK(!app.move('f', 0, 4));
  CHECK("Invalid move. Please enter your next move: " == app.getPrompt());

  // in game play mode
  CHECK(app.move('c', 0, 0));
  CHECK(TOP_LEFT_CLICKED +
            "Choose your next move(c or f) and cell, e.g. c 0 3 to click row "
            "zero column 3: " ==
        app.getPrompt());

  // valid moves
  CHECK(app.move('C', 0, 3));  // both upper and lower cases are accepted
  CHECK(app.move('c', 3, 2));
  CHECK(!app.move('c', 3, 2));  // cannot click the clicked cell!
  CHECK(app.move('f', 1, 3));  // first time to flag
  CHECK(app.move('f', 1, 3));  // flag toggled
  CHECK(app.move('f', 1, 3));  // flagged again
  CHECK(FLAG_ADDED +
            "Choose your next move(c or f) and cell, e.g. c 0 3 to click row "
            "zero column 3: " ==
        app.getPrompt());

  // Reveal more
  CHECK(app.move('c', 3, 0));
  CHECK(app.move('c', 2, 1));
  CHECK(!app.gameIsOver());

  // winning move
  CHECK(app.move('c', 2, 2));
  CHECK(CLEARED_MINEFIELD + "You Win!" == app.getPrompt());
  CHECK(app.gameIsOver());
}

TEST_CASE("Clicked on mine") {
  TextMenuApp app;
  CHECK(app.load("test/four-by-four.in"));

  CHECK(app.move('c', 3, 3));  // click mine
  CHECK(MINES_UNEARTHED + "Game Over!" == app.getPrompt());
  CHECK(app.gameIsOver());
}