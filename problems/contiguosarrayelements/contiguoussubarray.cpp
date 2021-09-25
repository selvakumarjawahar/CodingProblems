//
// Created by selva on 12-07-2020.
//

#include "contiguoussubarray.h"

std::vector<int> contiguous_subarray::CountSubarrays(std::vector<int> arr) {
  std::vector<int> result(arr.size(),1);
  int count=0;
  int index = 0;
  for(int i =0; i<arr.size() ; i++) {
    count = 0;
    index = i - 1;
    while (index >= 0) {
      if (arr[i] > arr[index]) {
        count++;
        index--;
      } else
        break;
    }
    index = i + 1;
    while (index < arr.size()) {
      if (arr[i] > arr[index]) {
        count++;
        index++;
      } else
        break;
    }
    result[i] = result[i] + count;
  }
  return result;
}
