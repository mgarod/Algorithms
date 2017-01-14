#include <iostream>
#include <vector>
using namespace std;

struct Node {
  Node() = delete;
  Node(int d) : data(d), left(nullptr), right(nullptr) { };
  int data;
  Node* left, *right;
};

class BST {
 public:
  BST() : head(nullptr) { };
  void insert(int d);
  bool contains(int d) const;
  void inorder() const;
  void preorder() const;
  void postorder() const;
 private:
  Node* head;
  void inorderHelper(Node* n) const;
  void preorderHelper(Node* n) const;
  void postorderHelper(Node* n) const;
};

void BST::insert(int d) {
  if (head == nullptr) {
    head = new Node(d);
    return;
  }

  Node* cursor = head;
  while (cursor != nullptr) {
    if (d < cursor->data) {
      if (cursor->left == nullptr) {
        cursor->left = new Node(d);
        return;
      } else {
        cursor = cursor->left;
      }
    } else {
      if (cursor->right == nullptr) {
        cursor->right = new Node(d);
        return;
      } else {
        cursor = cursor->right;
      }
    }
  }
}

bool BST::contains(int d) const {
  Node* cursor = head;
  while (cursor != nullptr) {
    if (cursor->data == d) {
      return true;
    } else if (d < cursor->data) {
      cursor = cursor->left;
    } else {
      cursor = cursor->right;
    }
  }
  return false;
}

void BST::inorder() const {
  if (head == nullptr) {
    cout << "tree is empty" << endl;
    return;
  }
  inorderHelper(head);
  cout << endl;
}
void BST::inorderHelper(Node* n) const {
  if(n == nullptr)
    return;

  inorderHelper(n->left);
  cout << n->data << " ";
  inorderHelper(n->right);
}

void BST::preorder() const {
  if (head == nullptr) {
    cout << "tree is empty" << endl;
    return;
  }
  preorderHelper(head);
  cout << endl;
}
void BST::preorderHelper(Node* n) const {
  if(n == nullptr)
    return;

  cout << n->data << " ";
  preorderHelper(n->left);
  preorderHelper(n->right);
}

void BST::postorder() const {
  if (head == nullptr) {
    cout << "tree is empty" << endl;
    return;
  }
  postorderHelper(head);
  cout << endl;
}
void BST::postorderHelper(Node* n) const {
  if(n == nullptr)
    return;

  postorderHelper(n->left);
  postorderHelper(n->right);
  cout << n->data << " ";
}

int main() {
  vector<int> v = {7,3,9,1,4,8,10};
  BST bst;
  for (int i = 0; i < v.size(); ++i)
    bst.insert(v[i]);

 bst.inorder(); 
 bst.preorder(); 
 bst.postorder(); 
}