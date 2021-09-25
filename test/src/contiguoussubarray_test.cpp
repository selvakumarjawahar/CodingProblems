//
// Created by selva on 12-07-2020.
//

#include "contiguosarrayelements/contiguoussubarray.h"

#include <bandit/bandit.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace snowhouse;
using namespace bandit;


// Tell bandit there are tests here.
go_bandit([]() {
  describe("testing contiguous array", []() {
             it("test case - 1", [&]() {
               std::vector<int> inp{3,4,1,6,2};
               std::vector<int> expected{1, 3, 1, 5, 1};
               auto actual = contiguous_subarray::CountSubarrays(inp);
               AssertThat(actual,Equals(expected));
             });
             it("test case - 2", [&]() {
               std::vector<int> inp{2, 4, 7, 1, 5, 3};
               std::vector<int> expected{1, 2, 6, 1, 3, 1};
               auto actual = contiguous_subarray::CountSubarrays(inp);
               AssertThat(actual,Equals(expected));
             });

           },
           false);

});
