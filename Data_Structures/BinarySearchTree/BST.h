#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct TreeNode {
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
  int val;
  TreeNode *left, *right;
};

class BST {
  public:
    BST() : root(nullptr) { }
    void insert(const int& x);
    bool contains(const int& x) const;
    bool remove(const int& x);
    void printInorder() const;
    void printPreorder() const;
    void printPostorder() const;

  private:
    TreeNode* root;
    void insertHelper(TreeNode*& p, const int& x);
    void printInorderHelper(TreeNode* p) const;
    void printPreorderHelper(TreeNode* p) const;
    void printPostorderHelper(TreeNode* p) const;
    TreeNode* findLeftmost(TreeNode* p) const;
};

#endif