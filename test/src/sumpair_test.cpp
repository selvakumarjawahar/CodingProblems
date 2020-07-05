//
// Created by selva on 05-07-2020.
//

#include "pairsum/sumpair.h"

#include <bandit/bandit.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace snowhouse;
using namespace bandit;


// Tell bandit there are tests here.
go_bandit([]() {
  describe("test sumpair problem", []() {
    it("test with simple case", [&]() {
      std::vector<int> inp{4,2,3,3,5,1,6,0};
      auto count = sumpair::findSumPair(inp,6);
      AssertThat(count,Equals(4));
    });

  },
      true);

});
