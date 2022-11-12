#include "text-menu-app.hpp"


TextMenuApp::TextMenuApp(){
  winner = false;
  gameOver = false;
  validFile = false;
  validMove = true;
}

void TextMenuApp::run(){

  char action;
  int row = 0;
  int col = 0;
  std::string file = "";

  while(!gameOver){
    while (!validFile){
      while(true){
        std::cout << getPrompt();
        getline(std::cin, file);
        if(!file.empty())
          break;
      }
      std::cout << std::endl;
      load(file);
    }

    std::cout << getPrompt();
    std::cin >> action >> row >> col;
    std::cout << std::endl;
    move(action, row, col);
  }
  std::cout << getPrompt() << std::endl;

}

std::string TextMenuApp::getPrompt() {
  std::string file;
  // print out the board
  // print the message to get the next move
  // return the move if valid
  if (!validFile){
    return "Please enter a file name with the minefield information: ";
  }

  if(winner){
    b.revealMines();
    return b.str() + "You Win!";
  }

  if(gameOver && !winner){
    b.revealMines();
    return b.str() + "Game Over!";
  }

  if(!validMove){
    return "Invalid move. Please enter your next move: ";
  }

  if(validMove) {
      return b.str() +
            "Choose your next move(c or f) and cell, e.g. c 0 3 to click row zero column 3: ";
  }
  
  return "";
}

bool TextMenuApp::move(char moveChar, int row, int col){
  
  if(checkMoveValidity(moveChar, row, col)){
    if (std::tolower(moveChar) == 'c') {
      bool valid = b.click(row, col);
      if(b.isMine(row, col)){
        gameOver = true;
        winner = false;
      }
      checkForWin();
      return valid;
    }
    else {
      return b.flag(row, col);
    }
  }
  return false;
}

bool TextMenuApp::checkMoveValidity(char moveChar, int row, int col){
  validMove = false;

  if(b.inbounds(row, col) && (std::tolower(moveChar) == 'c' || std::tolower(moveChar) == 'f')){
    validMove = true;
  }
  
  return validMove;
}

bool TextMenuApp::gameIsOver(){

  return gameOver;
}

void TextMenuApp::checkForWin(){
  if(b.checkWin()){
    gameOver = true;
    winner = true;
  }
}

bool TextMenuApp::load(std::string filename){
  validFile = b.load(filename);
   
   return validFile;
}