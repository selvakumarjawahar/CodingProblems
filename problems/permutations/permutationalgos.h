//
// Created by selva on 04-07-2020.
//

#ifndef SOLUTIONS_PERMUTATIONALGOS_H
#define SOLUTIONS_PERMUTATIONALGOS_H

#include <vector>
#include <iostream>

namespace permutation_algos {


template <typename T>
void printVector(const T& vec)
{
  for (auto elem : vec)
    std::cout << elem << " ";
  std::cout << '\n';
}

template <typename T>
void heapPermutation(T collection, size_t count)
{
  // if size becomes 1 then prints the obtained
  // permutation

  if (count == 1)
  {
    printVector(collection);
    return;
  }

  for (int i=0; i<count; i++)
  {
    heapPermutation(collection,count-1);

    if (count%2==1)
      std::swap(collection[0], collection[count-1]);

      // If size is even, swap ith and last
      // element
    else
      std::swap(collection[i], collection[count-1]);
  }
}

template <typename T>
void heapPermutationItr(T collection)
{
  std::vector<int> state(collection.size(),0);
  printVector(collection);

  int itr = 0;
  while(itr < collection.size() ){
    if (state[itr]<itr){
      if (itr%2==0)
        std::swap(collection[0], collection[itr]);
      else
        std::swap(collection[state[itr]], collection[itr]);
      printVector(collection);
      state[itr] = state[itr] + 1;
      itr = 0;
    }
    else{
      state[itr] = 0;
      ++itr;
    }
  }
}

template <typename T>
void heapPermutationItr(T collection, std::vector<T>& out)
{
  std::vector<int> state(collection.size(),0);
  out.push_back(collection);

  int itr = 0;
  while(itr < collection.size() ){
    if (state[itr]<itr){
      if (itr%2==0)
        std::swap(collection[0], collection[itr]);
      else
        std::swap(collection[state[itr]], collection[itr]);
      out.push_back(collection);
      state[itr] = state[itr] + 1;
      itr = 0;
    }
    else{
      state[itr] = 0;
      ++itr;
    }
  }
}

}

#endif // SOLUTIONS_PERMUTATIONALGOS_H
