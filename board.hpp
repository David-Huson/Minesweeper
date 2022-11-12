#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"

class Board {
  public:
    Board();
    ~Board();
    bool click(int row, int col);
    bool flag(int row, int col);
    bool load(std::string filename);
    std::string str();
    bool inbounds(int row,int col);
    bool checkWin();
    void revealMines();
  private:
    Cell** field;
    int cols;
    int rows;
    int numMines;
    int numCleared;
    void initField(std::string& fieldString);
    void incrementAdjMineCount(int row, int col);
    void countMines();
};
#endif