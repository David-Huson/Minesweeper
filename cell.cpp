#include "cell.hpp"

  const std::string Cell::MINE = "*";
  const std::string Cell::FLAG = "\u2691";
  const std::string Cell::NO_ADJACENT_MINES = "\u25A2";
  const std::string Cell::UNKNOWN = " ";


Cell::Cell(): isMine(false), isFlagged(false), isCleared(false), adjacentMineCount(0) {
  status = UNKNOWN;
}
/**
 * @brief Construct a new Cell given a boolean parameter to specify if it has a mine
 */
Cell::Cell(bool mine): isMine(mine), isFlagged(false), isCleared(false), adjacentMineCount(0) {
  status = UNKNOWN;
}

void Cell::setMine(){
  isMine = true;
}

bool Cell::click(){
  
  if(!isCleared && !isFlagged){    // if the cell has not been clicked

    isCleared = true;
    return true;
  }

  return false;  //  if the cell has already been clicked 

}

bool Cell::hasMine(){
  return this->isMine;
}
int Cell::getAdjacentMineCount(){
  return adjacentMineCount;
}

void Cell::setAdjacentMineCount(int mineCount){
  adjacentMineCount = mineCount;
}

void Cell::toggleFlag(){
  isFlagged = !isFlagged;
}

std::string Cell::str(){
  if(isCleared){
    if(isMine)
      return MINE;
    else if(getAdjacentMineCount() == 0)
      return NO_ADJACENT_MINES;
    else
      return std::to_string(getAdjacentMineCount());
    
  }
  else if(isFlagged)
    return FLAG;
  else 
    return UNKNOWN;
}