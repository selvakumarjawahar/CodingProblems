//
// Created by selva on 12-07-2020.
//

#ifndef SOLUTIONS_LINKEDLISTS_H
#define SOLUTIONS_LINKEDLISTS_H

#include <vector>
#include <iostream>

namespace linkedlists {

template <typename T>
struct Node {
  T Data;
  Node<T>* nextNode;
  Node<T>* prevNode;
  explicit Node(T Data):nextNode{nullptr},
                 prevNode{nullptr},
                 Data{Data}
  {}
};

template <typename T>
class SingleLinkedList {
public:
  explicit SingleLinkedList():headPtr{nullptr},
                                count{0}
  {}
  void insert(const T& data) {
    auto *node_ptr = new Node<T>(data);
    node_ptr->nextNode = headPtr;
    headPtr = node_ptr;
    count++;
  }
  std::vector<T> copyNodeData(){
    std::vector<T> outp;
    auto *tptr = headPtr;
    while(tptr != nullptr){
      outp.push_back(tptr->Data);
      tptr = tptr->nextNode;
    }
    return outp;
  }
  int getSize(){
    return count;
  }
  /*
  void reverse(){
    auto *cur_ptr = headPtr;
    auto *next_ptr = cur_ptr->nextNode;
    cur_ptr->nextnode = nullptr;
    while(cur_ptr != nullptr){
      auto tptr = next_ptr->nextNode;
      cur_ptr = next_ptr;
      next_ptr = tptr;
      cur_ptr->nextNode = nullptr;
      tptr->nextNode =
    }
  }
 */
  ~SingleLinkedList(){
    while(headPtr != nullptr){
      auto *tptr = headPtr;
      headPtr = tptr->nextNode;
      delete tptr;
    }
  }

private:
   Node<T> *headPtr;
   int count;
};
}

#endif // SOLUTIONS_LINKEDLISTS_H
