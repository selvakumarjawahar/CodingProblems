//
// Created by selva on 17-07-2020.
//

#ifndef SOLUTIONS_LEETFBLINKEDLIST_H
#define SOLUTIONS_LEETFBLINKEDLIST_H

#include "iostream"
#include <map>

namespace leetfb_linkedlist {
/**
 * Definition for singly-linked list.
*/

struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

template <typename T>
T* insert(T* head, int val){
    T* tptr = head;
    head = new T(val);
    head->next =tptr;
    return head;
}

template <typename T>
T* reverse(T* head) {
    T *prev = nullptr;
    T *next = nullptr;
    T *current = head;
    while ( current != nullptr ){
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
    return head;
}

template <typename T>
void printList(T* head) {
    while( head != nullptr ){
      std::cout << head->val << '\n';
      head = head->next;
    }
    return;
}

template <typename T>
bool compare(T* n1, T* n2) {
    while(n1 != nullptr && n2 != nullptr){
      if( n1->val != n2->val ) return false;
      n1 = n1->next;
      n2 = n2->next;
    }
    if ( n1 != nullptr || n2 != nullptr ) return false;
    return true;
}

template <typename T>
void freeList(T* head){
    while(head != nullptr){
      auto *tptr = head;
      head = tptr->next;
      delete tptr;
    }
}

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
  Node* copyRandomList(Node* head);
  void reorderList(ListNode* head);
};

}

#endif // SOLUTIONS_LEETFBLINKEDLIST_H

