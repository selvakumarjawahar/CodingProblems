//
// Created by selva on 05-07-2020.
//
#include "sumpair.h"

int sumpair::findSumPair(std::vector<int> sequence, int target_sum) {
  std::sort(sequence.begin(),sequence.end());
  auto itr = sequence.begin();
  auto count = 0;
  do{
    auto op = target_sum - *itr;
    if (op < 0 )return count;
    auto f_itr = std::find(itr+1,sequence.end(),op);
    if(f_itr != sequence.end()) count++;
  }while(++itr != sequence.end());
  return count;
}

