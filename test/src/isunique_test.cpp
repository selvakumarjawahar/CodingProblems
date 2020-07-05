//
// Created by selva on 04-07-2020.
//

#include "isunique/isunique.h"

#include <bandit/bandit.h>

using namespace snowhouse;
using namespace bandit;

// Tell bandit there are tests here.
go_bandit([]() {
  // We're describing how a fuzzbox works.
  describe("test the isunique problem", []() {

    it("test with a unique string", [&]() {
      AssertThat(true, Equals(isunique("qwerty")));
    });

    it("test with a non unique string", [&]() {
      AssertThat(false, Equals(isunique("qwertyqwerty")));
    });

  },true);
});
