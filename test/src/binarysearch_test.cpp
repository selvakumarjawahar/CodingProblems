//
// Created by selva on 01-08-2020.
//

#include "treealgos/binarysearchtree.h"

#include <bandit/bandit.h>
#include <vector>
#include <iostream>

using namespace snowhouse;
using namespace bandit;
using namespace binary_search_tree;
// Tell bandit there are tests here.
go_bandit([]() {
  // We're describing how a fuzzbox works.
  describe("test the binary search tree", []() {

    it("insert binary search tree", [&]() {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();

      insertNode(tree,new TreeNode<int>{5});
      insertNode(tree,new TreeNode<int>{4});
      insertNode(tree,new TreeNode<int>{7});
      insertNode(tree,new TreeNode<int>{2});
      insertNode(tree,new TreeNode<int>{3});
      insertNode(tree,new TreeNode<int>{6});
      insertNode(tree,new TreeNode<int>{8});

      std::vector<TreeNode<int>*> actual;
      inOrder(tree,actual);
      std::vector<int> expected{2,3,4,5,6,7,8};
      AssertThat(actual.size(),Equals(expected.size()));
      for(int i =0 ; i<actual.size();i++){
        AssertThat(actual[i]->data, Equals(expected[i]));
      }

      std::vector<TreeNode<int>*>{}.swap(actual);
      std::vector<int>{5,4,2,3,7,6,8}.swap(expected);
      preOrder(tree,actual);
      AssertThat(actual.size(),Equals(expected.size()));
      for(int i =0 ; i<actual.size();i++){
        AssertThat(actual[i]->data, Equals(expected[i]));
      }

      std::vector<TreeNode<int>*>{}.swap(actual);
      std::vector<int>{3,2,4,6,8,7,5}.swap(expected);
      postOrder(tree,actual);
      AssertThat(actual.size(),Equals(expected.size()));
      for(int i =0 ; i<actual.size();i++){
        AssertThat(actual[i]->data, Equals(expected[i]));
      }

    });

    it("test search in binary search tree", [&]() {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();

      insertNode(tree,new TreeNode<int>{5});
      insertNode(tree,new TreeNode<int>{4});
      insertNode(tree,new TreeNode<int>{7});
      insertNode(tree,new TreeNode<int>{2});
      insertNode(tree,new TreeNode<int>{3});
      insertNode(tree,new TreeNode<int>{6});
      insertNode(tree,new TreeNode<int>{8});

      auto node = searchNode(tree, 8);
      AssertThat(node->data,Equals(8));

    });

    it("test max value", [&]() {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();

      insertNode(tree,new TreeNode<int>{5});
      insertNode(tree,new TreeNode<int>{4});
      insertNode(tree,new TreeNode<int>{7});
      insertNode(tree,new TreeNode<int>{2});
      insertNode(tree,new TreeNode<int>{3});
      insertNode(tree,new TreeNode<int>{6});
      insertNode(tree,new TreeNode<int>{8});

      auto node = treeMax(tree);
      AssertThat(node->data,Equals(8));

    });

    it("test min value", [&]() {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();

      insertNode(tree,new TreeNode<int>{5});
      insertNode(tree,new TreeNode<int>{4});
      insertNode(tree,new TreeNode<int>{7});
      insertNode(tree,new TreeNode<int>{2});
      insertNode(tree,new TreeNode<int>{3});
      insertNode(tree,new TreeNode<int>{6});
      insertNode(tree,new TreeNode<int>{8});

      auto node = treeMin(tree);
      AssertThat(node->data,Equals(2));

    });

    it("test deletion of node", [&]() {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();

      insertNode(tree,new TreeNode<int>{5});
      insertNode(tree,new TreeNode<int>{4});
      insertNode(tree,new TreeNode<int>{7});
      insertNode(tree,new TreeNode<int>{2});
      insertNode(tree,new TreeNode<int>{3});
      insertNode(tree,new TreeNode<int>{6});
      insertNode(tree,new TreeNode<int>{8});

      auto node = searchNode(tree,8);
      deleteNode(tree,node);
      auto max = treeMax(tree);
      AssertThat(max->data,Equals(7));
    });


  },false);
});
