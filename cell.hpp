#ifndef CELL_HPP
#define CELL_HPP

#include <string>
class Cell {
  public:
    static const std::string MINE;
    static const std::string FLAG;
    static const std::string NO_ADJACENT_MINES;
    static const std::string UNKNOWN;
    bool hasMine();
    Cell();
    Cell(bool mine);
    void setMine();
    int getAdjacentMineCount();
    void toggleFlag();
    void setAdjacentMineCount(int mineCount);
    bool click();
    std::string str();
  private:
    bool isMine;
    bool isFlagged;
    bool isCleared;
    int adjacentMineCount;
    std::string status;
};
#endif