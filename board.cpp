#include "board.hpp"
#include <fstream>
#include <string>
  const std::string hBorder = "    +---+---+---+---+";
  const std::string vBorder = " |";
  Board::Board(){
    rows = 0;
    cols = 0;
    numMines = 0;
    numCleared = 0;
  }

  Board::~Board() {
    for(int i = 0; i < cols; i++){
      delete [] field[i];
    }
    delete [] field;
  }

  bool Board::load(std::string filename){
    std::ifstream file(filename);
    std::string fieldString = "";
    bool isFirstRow = true;

    if(!file.fail()){
      char c;
      while(file.get(c)){
        fieldString += std::string(1, c);
        if(c == '\n'){
          cols++;
          isFirstRow = false;
        }
        if(isFirstRow)
          rows++;
      }

      initField(fieldString);
      return true;
    }
    return false;
  }

  std::string Board::str() {
    std::string board = "    ";
    for(int i = 0; i < cols; ++i) {
      board += "  " + std::to_string(i) + " ";
    }
    board += '\n';
    board += hBorder + '\n';
    for(int row = 0; row < rows; row++){
      board += "  " + std::to_string(row) + vBorder;
      for(int col = 0; col < cols; col++){

        Cell cell = field[row][col];
        std::string cellStatus = cell.str();
        board += " " + cellStatus + vBorder;        
      }
      board += '\n';
      board += hBorder + '\n';
    }
    return board;
  }

  void Board::initField(std::string &fieldString) {
    // create a blank field of cells
    field = new Cell*[rows];
    for(int i = 0; i < rows; ++i)
      field[i] = new Cell[cols];

    // populate the field
    int row = 0;
    int col = 0;
      
    for(char c: fieldString){
      if (c == '\n') {
        row++;
        col = 0;
      }
      else if (c == '*') {
        field[row][col++].setMine();
        numMines++;
      } else {
        col++;
      }
    }

    countMines();
  }

  void Board::countMines() {
      for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
          if(field[row][col].hasMine()) {
            incrementAdjMineCount(row + 1, col);     // check cell to the east
            incrementAdjMineCount(row, col - 1);     // check cell to the north
            incrementAdjMineCount(row - 1, col);     // check cell to the west
            incrementAdjMineCount(row, col + 1);     // check cell to the south
            incrementAdjMineCount(row + 1, col - 1); // check cell to the north east
            incrementAdjMineCount(row - 1, col - 1); // check cell to the north west
            incrementAdjMineCount(row - 1, col + 1); // check cell to the south west
            incrementAdjMineCount(row + 1, col + 1); // check cell to the south east
          }
        }
      }
  }

  bool Board::click(int row, int col){

      if(inbounds(row, col)) { // check that row and col are valid
        Cell& cell = field[row][col];
        std::string cellStatus = cell.str();

        if(cellStatus != Cell::UNKNOWN) {   // make sure the cell hasn't already been clicked or flagged
            return false;
        }

        if(cell.hasMine()) {    // make sure we dont click a mine accidentally and stop clicking when we reach a cell with adjacent mines
          cell.click();
          return true;
        }

        cell.click();   // click to reveal the cell status

        if(cell.getAdjacentMineCount() != 0){
          numCleared++;
          return true;
        }

        /*
                NW   N   NE
                  \  | /
                W--Cell--E
                  / | \
                SW  S  SE 
        */
        // try clicking all surrounding cells (N, S, E, W, NE, NW, SE, SW)
        numCleared++;
        click(row - 1, col - 1);  // click cell to the north west
        click(row, col - 1);      // click cell to the west
        click(row + 1, col - 1);  // click cell to the south west
        click(row - 1, col);      // click cell to the north
        click(row + 1, col);      // click cell to the south
        click(row - 1, col + 1);  // click cell to the south east
        click(row, col + 1);      // click cell to the north
        click(row + 1, col + 1);  // click cell to the north east
        return true;
      }
      return false;
  }
  void Board::incrementAdjMineCount(int row, int col) {
    if(inbounds(row, col)){
      Cell& cell = field[row][col];
      if(!cell.hasMine())
        cell.setAdjacentMineCount(cell.getAdjacentMineCount() + 1);
    }
  }

  bool Board::inbounds(int row,int col){

    if(col > cols - 1 || col < 0 || row > rows - 1 || row < 0)  
      return false; 
    
    return true;
  }

  bool Board::flag(int row, int col){
    if(!inbounds(row, col)) {
      return false;
    }
    else {
      field[row][col].toggleFlag();
      return true;
    }
  }

  bool Board::checkWin() {
    int numCells = rows * cols;
    if(numMines ==  numCells - numCleared && numCleared != 0)
      return true;
    
    return false;
  }

  void Board::revealMines() {
    for(int row = 0; row < rows; row++){
      for(int col = 0; col < cols; col++){
        if(field[row][col].hasMine()){
          field[row][col].click();
        }
      }
    }
  }
