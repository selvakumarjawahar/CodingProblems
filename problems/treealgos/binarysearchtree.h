//
// Created by selva on 01-08-2020.
//

#ifndef SOLUTIONS_BINARYSEARCHTREE_H
#define SOLUTIONS_BINARYSEARCHTREE_H
#include <vector>

namespace binary_search_tree {

template <typename T> struct TreeNode {
  T data;
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(T data)
      : data{data}, parent{nullptr}, left{nullptr}, right{nullptr} {}
  ~TreeNode() {
    if (parent)
      delete parent;
    if (left)
      delete left;
    if (right)
      delete right;
  }
};

template <typename T> struct BinarySearchTree {
  TreeNode<T> *root;
  BinarySearchTree() : root{nullptr} {}
  ~BinarySearchTree() {
    if (root)
      delete root;
  }
};

template <typename T>
void insertNode(BinarySearchTree<T> *tree, TreeNode<T> *node) {
  if (node == nullptr){
    return;
  }
  if (tree->root == nullptr) {
    tree->root = node;
    return;
  }
  TreeNode<T> *parentNodePtr = nullptr;
  TreeNode<T> *nodeTraversePtr = tree->root;
  while (nodeTraversePtr != nullptr) {
    parentNodePtr = nodeTraversePtr;
    if (node->data < nodeTraversePtr->data)
      nodeTraversePtr = nodeTraversePtr->left;
    else
      nodeTraversePtr = nodeTraversePtr->right;
  }
  node->parent = parentNodePtr;
  if (node->data < parentNodePtr->data)
    parentNodePtr->left = node;
  else
    parentNodePtr->right = node;
  return;
}


template<typename T>
void inOrder(const BinarySearchTree<T>* tree, std::vector<TreeNode<T>*>& outp){
  if(tree->root == nullptr)return;
  inOrderRecurse(tree->root,outp);
}

template<typename T>
void preOrder(const BinarySearchTree<T>* tree, std::vector<TreeNode<T>*>& outp){
  if(tree->root == nullptr)return;
  preOrderRecurse(tree->root,outp);
}

template<typename T>
void postOrder(const BinarySearchTree<T>* tree, std::vector<TreeNode<T>*>& outp){
  if(tree->root == nullptr)return;
  postOrderRecurse(tree->root,outp);
}

template<typename T>
void deleteNode(BinarySearchTree<T>* tree, TreeNode<T>* node) {
  if(node->left == nullptr)
    Transplant(tree,node,node->right);
  else if(node->right == nullptr)
    Transplant(tree,node,node->left);
  else {
    auto minNode = NodeMin(node->right);
    if(minNode->parent == node) {
      Transplant(tree,node,minNode);
      minNode->left = node->left;
      minNode->left->parent = minNode;
    } else {
      Transplant(tree,minNode,minNode->right);
      minNode->right = node->right;
      minNode->right->parent = minNode;
    }
  }
}

template<typename T>
TreeNode<T>* searchNode(const BinarySearchTree<T>* tree,
                                T data) {
  TreeNode<T>* tptr = tree->root;
  while(tptr != nullptr){
    if(tptr->data == data)return tptr;
    if(data < tptr->data) tptr = tptr->left;
    if(data > tptr->data) tptr = tptr->right;
  }
  return tptr;
}

template<typename T>
TreeNode<T>* treeMax(BinarySearchTree<T>* tree){
  TreeNode<T>* tptr = tree->root;
  TreeNode<T>* maxNode = nullptr;
  while(tptr != nullptr){
    maxNode = tptr;
    tptr = tptr->right;
  }
  return maxNode;
}

template<typename T>
TreeNode<T>* treeMin(BinarySearchTree<T>* tree) {
  TreeNode<T>* tptr = tree->root;
  TreeNode<T>* minNode = nullptr;
  while(tptr != nullptr){
    minNode = tptr;
    tptr = tptr->left;
  }
  return minNode;
}

template<typename T>
static void inOrderRecurse(TreeNode<T>* node, std::vector<TreeNode<T>*>& outp ){
  if(node == nullptr)return;
  inOrderRecurse(node->left,outp);
  outp.push_back(node);
  inOrderRecurse(node->right,outp);
}

template<typename T>
static void preOrderRecurse(TreeNode<T>* node, std::vector<TreeNode<T>*>& outp ){
  if(node == nullptr)return;
  outp.push_back(node);
  preOrderRecurse(node->left,outp);
  preOrderRecurse(node->right,outp);
}

template<typename T>
static void postOrderRecurse(TreeNode<T>* node, std::vector<TreeNode<T>*>& outp ){
  if(node == nullptr)return;
  postOrderRecurse(node->left,outp);
  postOrderRecurse(node->right,outp);
  outp.push_back(node);
}

template<typename T>
static TreeNode<T>* NodeMin(TreeNode<T>* node) {
  TreeNode<T>* tptr = node;
  TreeNode<T>* minNode = nullptr;
  while(tptr != nullptr){
    minNode = tptr;
    tptr = tptr->left;
  }
  return minNode;
}

template<typename T>
static void Transplant(BinarySearchTree<T>* tree,
                       TreeNode<T>* replaceme, TreeNode<T>* replacewith) {
  if(replaceme->parent == nullptr){
    tree->root = replacewith;
  } else if(replaceme == replaceme->parent->left) {
    replaceme->parent->left = replacewith;
  } else {
    replaceme->parent->right = replacewith;
  }
  if(replacewith != nullptr)replacewith->parent = replaceme->parent;

}

}

#endif // SOLUTIONS_BINARYSEARCHTREE_H
