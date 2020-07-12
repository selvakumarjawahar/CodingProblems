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

           },
           false);

});
