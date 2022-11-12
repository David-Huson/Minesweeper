#ifndef TEXT_MENU_APP_HPP
#define TEXT_MENU_APP_HPP

#include "board.hpp"
#include <string>
#include <iostream>

class TextMenuApp {
    bool winner;
    bool gameOver;
    bool validFile;
    bool validMove;
    Board b;
    void checkForWin();
    void checkForLose();
    bool checkMoveValidity(char moveChar, int row, int col);
  public:
    TextMenuApp();
    void run();
    std::string getPrompt();
    bool move(char moveChar, int row, int col);
    bool gameIsOver();
    bool load(std::string filename);
};
#endif