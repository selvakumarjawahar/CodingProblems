//
// Created by selva on 17-07-2020.
//

#include "leetfblinkedlist.h"

leetfb_linkedlist::ListNode* leetfb_linkedlist::Solution::addTwoNumbers(
    ListNode *l1, ListNode *l2)
{
  leetfb_linkedlist::ListNode* result = nullptr;
  auto sum = 0;
  auto carry = 0;
  while(l1 != nullptr && l2 != nullptr){
    sum = l1->val + l2->val + carry;
    if(sum >= 10){
      sum = sum % 10;
      carry = 1;
    } else {
      carry = 0;
    }
    result = insert(result,sum);
    l1 = l1->next;
    l2 = l2->next;
  }
  while( l1 != nullptr){
    sum = l1->val + carry;
    if(sum >= 10){
      sum = sum % 10;
      carry = 1;
    } else {
      carry = 0;
    }
    result = insert(result,sum);
    l1 = l1->next;
  }
  while (l2 != nullptr ){
    sum = l2->val + carry;
    if(sum >= 10){
      sum = sum % 10;
      carry = 1;
    } else {
      carry = 0;
    }
    result = insert(result,sum);
    l2 = l2->next;
  }
  if( carry > 0 )result = insert(result,carry);
  return reverse(result);
}

leetfb_linkedlist::ListNode* leetfb_linkedlist::Solution::mergeTwoLists
    (ListNode *l1, ListNode *l2) {
  leetfb_linkedlist::ListNode *head = nullptr;
  while (l1 != nullptr && l2 != nullptr) {
    if(l1->val < l2->val ) {
      head = insert(head,l1->val);
      l1 = l1->next;
      continue;
    }
    else{
      head = insert(head,l2->val);
      l2 = l2->next;
      continue;
    }
  }
  while(l1 != nullptr){
    head = insert(head,l1->val);
    l1 = l1->next;
  }
  while(l2 != nullptr){
    head = insert(head,l2->val);
    l2 = l2->next;
  }
  return reverse(head);
}

leetfb_linkedlist::Node* leetfb_linkedlist::Solution::
    copyRandomList(Node *head) {
  if(head == nullptr)return nullptr;
  std::map<int,leetfb_linkedlist::Node*> original_node_random_map;
  std::map<leetfb_linkedlist::Node*,int> original_node_address_map;
  std::map<int,leetfb_linkedlist::Node*> copy_node_address_map;

  leetfb_linkedlist::Node* result = nullptr;
  auto node_count = 0;
  while(head != nullptr){
    result = insert(result,head->val);
    original_node_address_map[head] = node_count;
    original_node_random_map[node_count] = head->random;
    copy_node_address_map[node_count] = result;
    head = head->next;
    ++node_count;
  }
  auto *tptr = result;
  --node_count;
  while(tptr != nullptr ){
    auto *rand = original_node_random_map[node_count];
    if(rand == nullptr){
      tptr->random = nullptr;
      tptr = tptr->next;
      --node_count;
      continue;
    }
    auto node_index = original_node_address_map[rand];
    tptr->random = copy_node_address_map[node_index];
    tptr = tptr->next;
    --node_count;
  }
  return  reverse(result);
}

void leetfb_linkedlist::Solution::reorderList(ListNode *head) {
  if(head == nullptr) return;
  std::map<int,leetfb_linkedlist::ListNode*> node_addr_map;
  auto node_count = 0;
  leetfb_linkedlist::ListNode* tptr = head;
  while(tptr != nullptr){
    node_addr_map[node_count] = tptr;
    ++node_count;
    tptr = tptr->next;
  }
  int size = node_count;
  if(size < 2)return;
  --node_count;
  int i =0;
  leetfb_linkedlist::ListNode* current = head;
  while (i < size) {
    if (i % 2 == 0) {
      tptr = current->next;
      current->next = node_addr_map[node_count];
      current->next->next = tptr;
      current = current->next;
      --node_count;
      ++i;
      continue;
    }
    current = current->next;
    ++i;
  }
  if(size%2==0)  current->next = nullptr;
  else current->next->next = nullptr;
}