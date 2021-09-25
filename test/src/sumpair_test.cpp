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
      std::vector<int> inp{1,5,3,3,3};
      auto count = sumpair::findSumPair(inp,6);
      AssertThat(count,Equals(4));
    });

  },
      false);

});
