//
// Created by selva on 01-08-2020.
//

#include <bandit/bandit.h>
#include <leetfbarrays/leetfbarrays.h>

#include <vector>
#include <iostream>

using namespace snowhouse;
using namespace bandit;

static void print2d(const std::vector< std::vector<int> >& vector2d){
  std::cout << '\n';
  for(auto &outvec : vector2d) {
    std::cout<<"[";
    for(auto &invec : outvec){
      std::cout<<invec<<',';
    }
    std::cout<<"]"<<'\n';
  }
}

static bool isequal(const std::vector< std::vector<int> >& inp1,
                      const std::vector< std::vector<int> >& inp2){
  return !std::equal(inp1.begin(),inp1.end(),inp2.begin(),inp2.end());
}

// Tell bandit there are tests here.
go_bandit([]() {
  // We're describing how a fuzzbox works.

  describe("test the 3sum problem", []() {


    it("test case - 1", [&]() {
          std::vector<int> inp{-1, 0, 1, 2, -1, -4};
          std::vector<std::vector<int>> expected{
              {-1,-1,2},
              {-1,0,-1}
          };
          leetfb_arrays::Solution sol;
          auto actual = sol.threeSum(inp);
          AssertThat(isequal(actual,expected),Equals(true));
        });

  },false);
});
