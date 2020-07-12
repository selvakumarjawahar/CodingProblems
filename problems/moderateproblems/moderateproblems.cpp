//
// Created by selva on 05-07-2020.
//

#include "moderateproblems.h"

void moderate_problems::inplaceSwap(int &a, int &b){
  a=a+b;b=a-b;a=a-b;
}

std::unordered_map<std::string, int>
    moderate_problems::countWordFrequency(std::istringstream& str_stream) {
  std::unordered_map<std::string, int> hist;
  std::string tstr;
  while(std::getline(str_stream,tstr,' ')){
    if(hist.find(tstr) != hist.end()){
      hist[tstr]++;
    }else {
      hist[tstr]=1;
    }
  }
  return hist;
}
static const std::vector<std::bitset<9>> winning_bitmask{
    111000000,
    000111000,
    000000111,
    100100100,
    010010010,
    001001001,
    100010001,
    001010100,
};
//boardstate x,o,e "e for empty"
bool moderate_problems::isTicTacToeWon(const std::string &board_state) {
  std::string bitstring;
  for(auto& elem:board_state){
    if(elem=='x')bitstring.push_back('1');
    else bitstring.push_back('0');
  }
  std::bitset<9> bitset_x{bitstring};
  std::cout << "xbitstring = "<<bitset_x<< '\n';

  std::string{}.swap(bitstring);

  for(auto& elem:board_state){
    if(elem=='o')bitstring.push_back('1');
    else bitstring.push_back('0');
  }
  std::bitset<9> bitset_o{bitstring};
  std::cout << "obitstring = "<<bitset_o << '\n';

  for(auto elem:winning_bitmask){
    std::bitset<9> temp{bitset_x};
    std::cout << "temp and elem "<<temp<<'\t'<<elem<<'\n';
    //temp &= elem;
    //if(temp == elem){
      //std::cout << "temp and elem" <<'\t'<< temp <<'\t'<< elem << '\n';
      //return true;
  }


  /*
  for(auto elem:winning_bitmask){
    std::bitset<9> temp{bitset_o};
    std::cout << "temp and elem "<<temp<<'\t'<<elem<<'\n';
    temp &= elem;
    if(temp == elem) {
      std::cout << "temp and elem" <<'\t'<< temp <<'\t'<< elem << '\n';
      return true;
    }
  }
   */

  return false;
}



