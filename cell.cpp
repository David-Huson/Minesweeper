#include "cell.hpp"

  const std::string Cell::MINE = "*";
  const std::string Cell::FLAG = "\u2691";
  const std::string Cell::NO_ADJACENT_MINES = "\u25A2";
  const std::string Cell::UNKNOWN = " ";

/**
 * @brief Construct a new Cell given a boolean parameter to specify if it has a mine
 */
Cell::Cell(bool mine): isMine(mine), isFlagged(false), isCleared(false), adjacentMineCount(0) {
  status = UNKNOWN;
}

bool Cell::click(){

  if(isFlagged) {
    return false;
  }

  if(status == UNKNOWN){    // status will be UNKNOWN if the cell has not been clicked
    isCleared = true;

    if(isMine){
      status = MINE;
    }
    if(!isFlagged && !isMine && adjacentMineCount == 0) {
      status = NO_ADJACENT_MINES;
    }

    return true;  // return false if the cell has already been clicked (status not UNKNOWN)
  }

  return false;
}

bool Cell::hasMine(){
  return this->isMine;
}
int Cell::getAdjacentMineCount(){
  return adjacentMineCount;
}

void Cell::setAdjacentMineCount(int mineCount){
  adjacentMineCount = mineCount;
  status = std::to_string(adjacentMineCount);
}

void Cell::toggleFlag(){
  isFlagged = !isFlagged;
  status = (isFlagged) ? FLAG: UNKNOWN; // if true status = FLAG, else status = UNKNOWN
}

std::string Cell::str(){
  return status;
}