//
// Created by selva on 11-07-2020.
//

#include "ubench.h"
#include "permutations/permutationalgos.h"

#include <string>

std::string inp{"1234567"};
std::vector<std::string> outp;

UBENCH(HEAPS_PERMUTATION,STRING_INPUT_8_CHARS){
  permutation_algos::heapPermutationItr(inp,outp);
}