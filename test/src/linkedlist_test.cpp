//
// Created by selva on 12-07-2020.
//

#include <linkedlists/linkedlists.h>


#include <bandit/bandit.h>

#include <vector>

using namespace snowhouse;
using namespace bandit;


// Tell bandit there are tests here.
go_bandit([]() {
  describe("test linked list", []() {
             it("test insertion of 2 elements", [&]() {
               linkedlists::SingleLinkedList<int> list;
               list.insert(42);
               list.insert(10);
               std::vector<int> expected{10,42};
               auto actual = list.copyNodeData();
               AssertThat(list.getSize(),Equals(2));
               AssertThat(actual,Equals(expected));
             });

             it("test linked list reversal", [&]() {
               linkedlists::SingleLinkedList<int> list;
               list.insert(42);
               list.insert(10);
               list.insert(100);
               std::vector<int> expected{100,10,42};
               list.reverse();
               list.reverse();
               auto actual = list.copyNodeData();
               AssertThat(actual,Equals(expected));
             });

             it("test linked list loop detection", [&]() {
               linkedlists::SingleLinkedList<int> list;
               list.insert(42);
               list.insert(10);
               list.insert(100);
               list.insert(11);
               list.insert(120);
               list.insert(150);
               list.createLoop();
               AssertThat(list.isLoop(),Equals(true));
             });

           },
           false);

});
