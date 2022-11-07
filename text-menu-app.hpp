#ifndef TEXT_MENU_APP_HPP
#define TEXT_MENU_APP_HPP
class TextMenuApp {
  public:
    void run();
    std::string getPrompt();
    void move(std::string action, int col, int row);
    bool checkMoveValidity(std::string action, int col, int row);
    void initBoard(int cols, int rows);
};
#endif TEXT_MENU_APP_HPP