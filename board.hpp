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
  private:
    Cell** field;
    int cols;
    int rows;
    void initField(std::string& fieldString);
    void incrementAdjMineCount(int row, int col);
    bool inbounds(int row,int col);
    void countMines();
};
#endif