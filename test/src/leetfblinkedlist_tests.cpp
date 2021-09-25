//
// Created by selva on 17-07-2020.
//

#include "leetfacebooklinkedlist/leetfblinkedlist.h"
#include <bandit/bandit.h>
#include <iostream>

using namespace snowhouse;
using namespace bandit;

// Tell bandit there are tests here.
go_bandit([]() {
  // We're describing how a fuzzbox works.
  describe(
      "test the add numbers problem",
      []() {
        leetfb_linkedlist::ListNode *op1 = nullptr;
        leetfb_linkedlist::ListNode *op2 = nullptr;
        leetfb_linkedlist::ListNode *outp = nullptr;
        leetfb_linkedlist::ListNode *result = nullptr;

        op1 = leetfb_linkedlist::insert(op1, 3);
        op1 = leetfb_linkedlist::insert(op1, 4);
        op1 = leetfb_linkedlist::insert(op1, 2);

        op2 = leetfb_linkedlist::insert(op2, 4);
        op2 = leetfb_linkedlist::insert(op2, 6);
        op2 = leetfb_linkedlist::insert(op2, 5);

        outp = leetfb_linkedlist::insert(outp, 8);
        outp = leetfb_linkedlist::insert(outp, 0);
        outp = leetfb_linkedlist::insert(outp, 7);

        leetfb_linkedlist::Solution sol;

        it("test with numbers of equal length ", [&]() {
          leetfb_linkedlist::Solution sol;
          result = sol.addTwoNumbers(op1,op2);
          AssertThat(
              leetfb_linkedlist::compare(result,outp),Equals(true));
        });

        op2 = leetfb_linkedlist::insert(op2, 5);
        leetfb_linkedlist::freeList(outp);
        outp = nullptr;
        outp = leetfb_linkedlist::insert(outp, 4);
        outp = leetfb_linkedlist::insert(outp, 9);
        outp = leetfb_linkedlist::insert(outp, 9);
        outp = leetfb_linkedlist::insert(outp, 7);

        it("test with numbers of unequal length - 1 ", [&]() {
          leetfb_linkedlist::Solution sol;
          result = sol.addTwoNumbers(op1,op2);
          AssertThat(
              leetfb_linkedlist::compare(result,outp),Equals(true));
        });

        op1 = leetfb_linkedlist::insert(op1, 2);
        op1 = leetfb_linkedlist::insert(op1, 2);
        leetfb_linkedlist::freeList(outp);
        outp = nullptr;
        outp = leetfb_linkedlist::insert(outp, 3);
        outp = leetfb_linkedlist::insert(outp, 8);
        outp = leetfb_linkedlist::insert(outp, 8);
        outp = leetfb_linkedlist::insert(outp, 7);
        outp = leetfb_linkedlist::insert(outp, 7);

        it("test with numbers of unequal length - 2 ", [&]() {
          leetfb_linkedlist::Solution sol;
          result = sol.addTwoNumbers(op1,op2);
          AssertThat(
              leetfb_linkedlist::compare(result,outp),Equals(true));
        });

        leetfb_linkedlist::freeList(op1);
        leetfb_linkedlist::freeList(op2);
        leetfb_linkedlist::freeList(outp);
        leetfb_linkedlist::freeList(result);

      },
      true);

  describe(
      "test the merging sorted list problem",
      []() {
        leetfb_linkedlist::ListNode *op1 = nullptr;
        leetfb_linkedlist::ListNode *op2 = nullptr;
        leetfb_linkedlist::ListNode *outp = nullptr;
        leetfb_linkedlist::ListNode *result = nullptr;

        op1 = leetfb_linkedlist::insert(op1, 3);
        op1 = leetfb_linkedlist::insert(op1, 2);
        op1 = leetfb_linkedlist::insert(op1, 1);

        op2 = leetfb_linkedlist::insert(op2, 6);
        op2 = leetfb_linkedlist::insert(op2, 5);
        op2 = leetfb_linkedlist::insert(op2, 4);

        outp = leetfb_linkedlist::insert(outp, 6);
        outp = leetfb_linkedlist::insert(outp, 5);
        outp = leetfb_linkedlist::insert(outp, 4);
        outp = leetfb_linkedlist::insert(outp, 3);
        outp = leetfb_linkedlist::insert(outp, 2);
        outp = leetfb_linkedlist::insert(outp, 1);

        leetfb_linkedlist::Solution sol;

        it("test with numbers of equal length ", [&]() {
          leetfb_linkedlist::Solution sol;
          result = sol.mergeTwoLists(op1,op2);

          AssertThat(
              leetfb_linkedlist::compare(result,outp),Equals(true));

        },false);

        leetfb_linkedlist::freeList(op1);
        op1 = nullptr;
        op1 = leetfb_linkedlist::insert(op1, 0);
        leetfb_linkedlist::freeList(op2);
        op2 = nullptr;
        op2 = leetfb_linkedlist::insert(op2, 1);
        op2 = leetfb_linkedlist::insert(op2, 0);
        leetfb_linkedlist::freeList(outp);
        outp = nullptr;
        outp = leetfb_linkedlist::insert(outp, 1);
        outp = leetfb_linkedlist::insert(outp, 0);
        outp = leetfb_linkedlist::insert(outp, 0);

        it("test with numbers of unequal length ", [&]() {
          leetfb_linkedlist::Solution sol;
          result = sol.mergeTwoLists(op1,op2);
          AssertThat(
              leetfb_linkedlist::compare(result,outp),Equals(true));
        },
            false);


        leetfb_linkedlist::freeList(op1);
        leetfb_linkedlist::freeList(op2);
        leetfb_linkedlist::freeList(outp);
        leetfb_linkedlist::freeList(result);

      },
      true);

  describe(
      "test the changing order problem",
      []() {
        leetfb_linkedlist::ListNode *op1 = nullptr;
        leetfb_linkedlist::ListNode *outp = nullptr;

        op1 = leetfb_linkedlist::insert(op1, 4);
        op1 = leetfb_linkedlist::insert(op1, 3);
        op1 = leetfb_linkedlist::insert(op1, 2);
        op1 = leetfb_linkedlist::insert(op1, 1);

        outp = leetfb_linkedlist::insert(outp, 3);
        outp = leetfb_linkedlist::insert(outp, 2);
        outp = leetfb_linkedlist::insert(outp, 4);
        outp = leetfb_linkedlist::insert(outp, 1);

        leetfb_linkedlist::Solution sol;

        it("test with even sized list ", [&]() {
          sol.reorderList(op1);

          AssertThat(
              leetfb_linkedlist::compare(op1,outp),Equals(true));

        },true);

        leetfb_linkedlist::freeList(op1);
        leetfb_linkedlist::freeList(outp);

        op1 = nullptr;
        outp = nullptr;

        op1 = leetfb_linkedlist::insert(op1, 5);
        op1 = leetfb_linkedlist::insert(op1, 4);
        op1 = leetfb_linkedlist::insert(op1, 3);
        op1 = leetfb_linkedlist::insert(op1, 2);
        op1 = leetfb_linkedlist::insert(op1, 1);

        outp = leetfb_linkedlist::insert(outp, 3);
        outp = leetfb_linkedlist::insert(outp, 4);
        outp = leetfb_linkedlist::insert(outp, 2);
        outp = leetfb_linkedlist::insert(outp, 5);
        outp = leetfb_linkedlist::insert(outp, 1);

        it("test with odd sized list ", [&]() {
          sol.reorderList(op1);
          AssertThat(
              leetfb_linkedlist::compare(op1,outp),Equals(true));

        },false);

        leetfb_linkedlist::freeList(op1);
        leetfb_linkedlist::freeList(outp);


      },
      false);


});
