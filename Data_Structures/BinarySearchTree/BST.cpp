#include "BST.h"

void BST::insert(const int& x) {
  if (root == nullptr) {
    root = new TreeNode(x);
    return;
  }

  TreeNode* p = root;
  while (true) {
    if (x == p->val) {
      return;
    } else if (x < p->val) {
      if (p->left == nullptr) {
        p->left = new TreeNode(x);
        return;
      } else {
        p = p->left;
      }
    } else {
      if (p->right == nullptr) {
        p->right = new TreeNode(x);
        return;
      } else {
        p = p->right;
      }
    }
  }
}

bool BST::contains(const int& x) const {
  if (root == nullptr) {
    return false;
  } else {
    TreeNode* p = root;
    while (p != nullptr) {
      if (x == p->val) {
        return true;
      } else if (x < p->val) {
        p = p->left;
      } else {
        p = p->right;
      }
    }
  }
  return false;
};

void BST::insertHelper(TreeNode*& p, const int& x) {
  if (p == nullptr) {
    p = new TreeNode(x);
  } else if (x == p->val) {
    // nothing, duplicate
  } else if (x < p->val) {
    insertHelper(p->left, x);
  } else {
    insertHelper(p->right, x);
  }
}

void BST::printInorder() const {
  if (root != nullptr)
    printInorderHelper(root);
  else
    cout << "tree is empty";
  cout << endl;
}

void BST::printInorderHelper(TreeNode* p) const {
  if (p->left != nullptr) printInorderHelper(p->left);
  cout << p->val << " ";
  if (p->right != nullptr) printInorderHelper(p->right);
}

void BST::printPreorder() const {
  if (root != nullptr)
    printPreorderHelper(root);
  else
    cout << "tree is empty";
  cout << endl;
}

void BST::printPreorderHelper(TreeNode* p) const {
  cout << p->val << " ";
  if (p->left != nullptr) printPreorderHelper(p->left);
  if (p->right != nullptr) printPreorderHelper(p->right);
}

void BST::printPostorder() const {
  if (root != nullptr)
    printPostorderHelper(root);
  else
    cout << "tree is empty";
  cout << endl;
}

void BST::printPostorderHelper(TreeNode* p) const {
  if (p->left != nullptr) printPostorderHelper(p->left);
  if (p->right != nullptr) printPostorderHelper(p->right);
  cout << p->val << " ";
}

bool BST::remove(const int& x) {
  if (!contains(x)) {
    return false;
  }

  // cout << "removing: " << x << endl;

  TreeNode *parent = root, *to_remove = nullptr;
  bool remove_left = true; // flag, useful for knowing where the removal is
  // special case removing the root, no need to enter loop
  if (root->val == x) {
    to_remove = root;
  } else {
    while (true) {
      if (x < parent->val) {
        if (parent->left->val == x) { // left child is removal candidate 
          to_remove = parent->left;
          break;
        } else {
          parent = parent->left;
        }
      } else { // if (x > parent->val)
        if (parent->right->val == x) { // right child is removal candidate
          to_remove = parent->right;
          remove_left = false;
          break;
        } else {
          parent = parent->right;
        }
      }
    }
  }

  // cout << "parent val: " << parent->val << endl;
  // cout << "remove val: " << to_remove->val << endl;

  // case removing a node with 2 children
  if (to_remove->left != nullptr && to_remove->right != nullptr) {
    // cout << "removing node with 2 children" << endl;
    int leftmost_val = findLeftmost(to_remove->right)->val;
    // cout << "leftmost_val: " << leftmost_val << endl;
    remove(leftmost_val);
    to_remove->val = leftmost_val;
  } else if (to_remove->left == nullptr && to_remove->right == nullptr) {
    // case removing a leaf
    // cout << "removing node with 0 children" << endl;  
    if (remove_left)
      parent->left = nullptr;
    else
      parent->right = nullptr;
    delete to_remove;
  } else { // case removing a node with 1 child
    // cout << "removing node with 1 child" << endl;
    if (remove_left)
      parent->left = to_remove->left? to_remove->left : to_remove->right;
    else 
      parent->right = to_remove->left? to_remove->left : to_remove->right;
    delete to_remove;
  }

  return true;
}

TreeNode* BST::findLeftmost(TreeNode* p) const{
  if (p == nullptr || p->left == nullptr)
    return p;
  else if (p->left->left != nullptr)
    return findLeftmost(p->left);
  else
    return p->left;
}