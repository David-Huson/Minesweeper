#include <string>
#include "../cell.hpp"

const std::string NOTHING_CLICKED =
"      0   1   2   3 \n"
"    +---+---+---+---+\n"
"  0 |   |   |   |   |\n"
"    +---+---+---+---+\n"
"  1 |   |   |   |   |\n"
"    +---+---+---+---+\n"
"  2 |   |   |   |   |\n"
"    +---+---+---+---+\n"
"  3 |   |   |   |   |\n"
"    +---+---+---+---+\n";

const std::string TOP_LEFT_CLICKED =
"      0   1   2   3 \n"
"    +---+---+---+---+\n"
"  0 | "+Cell::NO_ADJACENT_MINES+" | "+Cell::NO_ADJACENT_MINES+" | 1 |   |\n"
"    +---+---+---+---+\n"
"  1 | 1 | 1 | 2 |   |\n"
"    +---+---+---+---+\n"
"  2 |   |   |   |   |\n"
"    +---+---+---+---+\n"
"  3 |   |   |   |   |\n"
"    +---+---+---+---+\n";

const std::string BOTTOM_RIGHT_NUMBER_CLICKED =
"      0   1   2   3 \n"
"    +---+---+---+---+\n"
"  0 | "+Cell::NO_ADJACENT_MINES+" | "+Cell::NO_ADJACENT_MINES+" | 1 |   |\n"
"    +---+---+---+---+\n"
"  1 | 1 | 1 | 2 |   |\n"
"    +---+---+---+---+\n"
"  2 |   |   |   |   |\n"
"    +---+---+---+---+\n"
"  3 |   |   | 3 |   |\n"
"    +---+---+---+---+\n";

const std::string TOP_ROW_ALL_CLICKED =
"      0   1   2   3 \n"
"    +---+---+---+---+\n"
"  0 | "+Cell::NO_ADJACENT_MINES+" | "+Cell::NO_ADJACENT_MINES+" | 1 | 1 |\n"
"    +---+---+---+---+\n"
"  1 | 1 | 1 | 2 |   |\n"
"    +---+---+---+---+\n"
"  2 |   |   |   |   |\n"
"    +---+---+---+---+\n"
"  3 |   |   | 3 |   |\n"
"    +---+---+---+---+\n";

const std::string FLAG_ADDED =
"      0   1   2   3 \n"
"    +---+---+---+---+\n"
"  0 | "+Cell::NO_ADJACENT_MINES+" | "+Cell::NO_ADJACENT_MINES+" | 1 | 1 |\n"
"    +---+---+---+---+\n"
"  1 | 1 | 1 | 2 | "+Cell::FLAG+" |\n"
"    +---+---+---+---+\n"
"  2 |   |   |   |   |\n"
"    +---+---+---+---+\n"
"  3 |   |   | 3 |   |\n"
"    +---+---+---+---+\n";

const std::string MINES_UNEARTHED =
"      0   1   2   3 \n"
"    +---+---+---+---+\n"
"  0 |   |   |   |   |\n"
"    +---+---+---+---+\n"
"  1 |   |   |   | "+Cell::MINE+" |\n"
"    +---+---+---+---+\n"
"  2 | "+Cell::MINE+" |   |   | "+Cell::MINE+" |\n"
"    +---+---+---+---+\n"
"  3 |   | "+Cell::MINE+" |   | "+Cell::MINE+" |\n"
"    +---+---+---+---+\n";

const std::string CLEARED_MINEFIELD =
"      0   1   2   3 \n"
"    +---+---+---+---+\n"
"  0 | "+Cell::NO_ADJACENT_MINES+" | "+Cell::NO_ADJACENT_MINES+" | 1 | 1 |\n"
"    +---+---+---+---+\n"
"  1 | 1 | 1 | 2 | "+Cell::FLAG+" |\n"
"    +---+---+---+---+\n"
"  2 | "+Cell::MINE+" | 2 | 4 | "+Cell::MINE+" |\n"
"    +---+---+---+---+\n"
"  3 | 2 | "+Cell::MINE+" | 3 | "+Cell::MINE+" |\n"
"    +---+---+---+---+\n";
