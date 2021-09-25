//
// Created by selva on 15-07-2020.
//

#include "ubench.h"
#include <list>
#include <vector>
#include "linkedlists/linkedlists.h"

#define DOUBLE_COUNT 1000

UBENCH(LIST_COMPARE_INSTERSTION,MY_VECTOR) {
  std::vector<double> std_vector;
  for(int i = 1; i <= DOUBLE_COUNT; i++){
    std_vector.push_back(1/i);
  }
}

UBENCH(LIST_COMPARE_INSTERSTION,STD_LIST) {
  std::list<double> std_list;
  for(int i = 1; i <= DOUBLE_COUNT; i++){
    std_list.push_back(1/i);
  }
}

UBENCH(LIST_COMPARE_INSTERSTION,MY_LIST) {
  linkedlists::SingleLinkedList<double> my_list;
  for(int i = 1; i <= DOUBLE_COUNT; i++){
    my_list.insert(1/i);
  }
}
