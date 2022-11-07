#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"

class Board {
  public:
    void click(int col, int row);
    void flag(int col, int row);
    void clear(int col, int row);
  private:
    Cell** field;
    int cols;
    int rows;
    int numCells;
};
#endif