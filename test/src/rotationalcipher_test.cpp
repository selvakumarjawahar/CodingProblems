//
// Created by selva on 08-07-2020.
//

#include "rotationalcipher/rotationalcipher.h"

#include <bandit/bandit.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace snowhouse;
using namespace bandit;


// Tell bandit there are tests here.
go_bandit([]() {
  describe("test rotational cipher", []() {
             it("test-1", [&]() {
               std::string input_1 = "All-convoYs-9-be:Alert1.";
               auto cipher = rotational_cipher::rotationalCipher(input_1,4);
               AssertThat(cipher,Equals("Epp-gsrzsCw-3-fi:Epivx5."));
             });
             it("test-1", [&]() {
               std::string input_1 = "abcdZXYzxy-999.@";
               auto cipher = rotational_cipher::rotationalCipher(input_1,200);
               AssertThat(cipher,Equals("stuvRPQrpq-999.@"));
             });

           },false);

});

