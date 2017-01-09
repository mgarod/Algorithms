#include <iostream>
#include "BST.h"
using namespace std;

int main() {
  BST bst;
  bst.printInorder();
  bst.insert(8);
  bst.insert(4);
  bst.insert(12);
  bst.insert(6);
  bst.insert(11);
  bst.insert(19);
  bst.insert(14);
  bst.insert(1);
  bst.insert(3);
  bst.insert(15);
  bst.insert(13);
  bst.printInorder();
  cout << endl;

  for (int i = 0; i <= 20; ++i) {
    printf("contains %d?: %d\n", i, bst.contains(i));
  }
  
  cout << endl;
  cout << "removing 2-child 12? " << bst.remove(12) << endl;
  bst.printInorder();
  cout << "removing 1-child 1? " << bst.remove(1) << endl;
  bst.printInorder();
  cout << "removing 0-child 6? " << bst.remove(6) << endl;
  bst.printInorder();
  cout << "removing the root 8? " << bst.remove(8) << endl;
  bst.printInorder();
  cout << endl;
  
  for (int i = 0; i <= 20; ++i) {
    printf("contains %d?: %d\n", i, bst.contains(i));
  }

  return 0;
}