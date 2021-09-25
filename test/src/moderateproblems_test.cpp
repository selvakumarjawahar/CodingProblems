//
// Created by selva on 05-07-2020.
//

#include <bandit/bandit.h>

#include <iostream>
#include <unordered_map>
#include <sstream>

#include "moderateproblems/moderateproblems.h"

using namespace snowhouse;
using namespace bandit;


// Tell bandit there are tests here.
go_bandit([]() {
  describe("test moderate problem solutions", []() {
    it("test inline swap", [&]() {
      int a = 5, b = 8;
      moderate_problems::inplaceSwap(a,b);
      AssertThat(a,Equals(8));
      AssertThat(b,Equals(5));
    });

    it("test word hist", [&]() {
      std::istringstream strstream{"There is repetition here here"};
      auto word_map=moderate_problems::countWordFrequency(strstream);
      AssertThat(word_map.size(),Equals(4));
      AssertThat(word_map["There"],Equals(1));
      AssertThat(word_map["is"],Equals(1));
      AssertThat(word_map["repetition"],Equals(1));
      AssertThat(word_map["here"],Equals(2));
    });

    it("test tictactoe x wins", [&]() {
      auto win = moderate_problems::isTicTacToeWon("xxxooxoox");
      AssertThat(true,Equals(win));
    },true);

    it("test tictactoe o wins", [&]() {
      auto win = moderate_problems::isTicTacToeWon("xoooooxox");
      AssertThat(true,Equals(win));
    },true);

    it("test tictactoe draw", [&]() {
      auto win = moderate_problems::isTicTacToeWon("eoxoxoxoe");
      AssertThat(win,Equals(false));
    },false);
  },true);

});
