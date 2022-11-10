#ifndef TEXT_MENU_APP_HPP
#define TEXT_MENU_APP_HPP

#include <string>
class TextMenuApp {
    bool winner;
    bool gameOver;
  public:
    TextMenuApp();
    void run();
    std::string getPrompt();
    void move(std::string action, int row, int col);
    bool checkMoveValidity(std::string action, int row, int col);
};
#endif TEXT_MENU_APP_HPP