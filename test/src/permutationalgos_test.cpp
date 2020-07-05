//
// Created by selva on 04-07-2020.
//

#include "permutations/permutationalgos.h"
#include "factorial/factorial.h"

#include <bandit/bandit.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace snowhouse;
using namespace bandit;

// Tell bandit there are tests here.
go_bandit([]() {
  // We're describing how a fuzzbox works.
  describe("test generation of permutation using heap's algo Recurrsive", []() {

    it("test generation int", [&]() {
      std::vector<int> vec{1,2,3};
      permutation_algos::heapPermutation<std::vector<int>>(vec,vec.size());
    });

    it("test generation int", [&]() {
      std::string str{"se"};
      permutation_algos::heapPermutation<std::string>(str,str.size());
    },true);

  },true);

  describe("test generation of permutation using heap's algo Iterative", []() {

    it("test generation with output", [&]() {
      std::vector<std::vector<int>> result;
      std::vector<int> vec{1,2,3,4,5,6,7,8,9};
      permutation_algos::heapPermutationItr(vec,result);
      auto permutations = GenerateFactorial(vec.size());
      AssertThat(result.size(),Equals(permutations));
      for(auto& elem: result){
        AssertThat(true,
            Equals(
                std::is_permutation(vec.begin(),vec.end(),elem.begin()
                )
            ));
      }
      AssertThat(result.end(),
          Equals(
              std::unique(result.begin(),result.end()
              )
          ));
    });

  },true);

});
