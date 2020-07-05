//
// Created by selva on 05-07-2020.
//

#ifndef SOLUTIONS_MODERATEPROBLEMS_H
#define SOLUTIONS_MODERATEPROBLEMS_H

#include <string>
#include <unordered_map>
#include <sstream>
#include <array>
#include <bitset>
#include <iostream>

namespace moderate_problems {
void inplaceSwap(int& a, int& b);
std::unordered_map<std::string, int>
    countWordFrequency(std::istringstream& str_stream);
bool isTicTacToeWon(const std::string& board_state);
}



#endif // SOLUTIONS_MODERATEPROBLEMS_H
