//
// Created by selva on 12-07-2020.
//

#ifndef SOLUTIONS_LINKEDLISTS_H
#define SOLUTIONS_LINKEDLISTS_H

#include <vector>

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

  void reverse(){
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;
    auto *current = headPtr;
    while(current != nullptr){
      next = current->nextNode;
      current->nextNode = prev;
      prev = current;
      current = next;
    }
    headPtr = prev;
  }

  bool isLoop(){
    auto *slow_ptr = headPtr;
    auto *fast_ptr = headPtr;
    while(fast_ptr != nullptr && fast_ptr->nextNode != nullptr){
      slow_ptr = slow_ptr->nextNode;
      fast_ptr = fast_ptr->nextNode->nextNode;
      if(slow_ptr == fast_ptr)return true;
    }
    return false;
  }

  void createLoop(){
    auto *head = headPtr;
    auto *lag_ptr = headPtr;
    while(head != nullptr) {
      lag_ptr = head;
      head = head->nextNode;
    }
    lag_ptr->nextNode = headPtr;
  }

  ~SingleLinkedList(){
    /*
    while(headPtr != nullptr){
      auto *tptr = headPtr;
      headPtr = tptr->nextNode;
      delete tptr;
    }
    */
    for(int i = 0; i < count ; i++){
      auto *tptr = headPtr;
      headPtr = tptr->nextNode;
      if(tptr)
        delete tptr;
    }

  }

private:
   Node<T> *headPtr;
   int count;
};
}

#endif // SOLUTIONS_LINKEDLISTS_H
