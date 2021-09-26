//
// Created by selva on 9/25/21.
//

#include <vector>
#include <algorithm>

#include <bandit/bandit.h>

#include "../../problems/sortingalgos/mergesort.h"
using namespace snowhouse;
using namespace bandit;

// Tell bandit there are tests here.
go_bandit([]() {
  // We're describing how a fuzzbox works.
  describe("test the merge sort", []() {

        it("test with simple sequnce", []() {
          std::vector<int> to_sort = {43, 56, 67, 89, 12, 34};
          auto sorted = MergeSort(to_sort);
          AssertThat(true, Equals(std::is_sorted(sorted.begin(),sorted.end())));
        });

      },false);
});

