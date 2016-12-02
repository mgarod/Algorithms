#include <iostream>
using namespace std;

struct ListNode {
  ListNode(int v) : val(v), next(nullptr) { };
  int val;
  ListNode* next;
};

class List {
 public:
  List() : head(nullptr), size(0) { };
  void insert(int val);
  bool empty() { return size; };
  bool remove(int index);
  void print();
 private:
  ListNode* head;
  int size;
};

void List::insert(int val) {
  if (head == nullptr) {
    head = new ListNode(val);
  } else {
    ListNode* p = head;
    for (p; p->next != nullptr; p = p->next) { }
    p->next = new ListNode(val);
  }
  ++size;
}

bool List::remove(int index) {
  ListNode* p = head;
  if (index > size || index < 1) { // case of invalid
    return false;
  } else if (index == 1) { // case of remove head, index == 1
    head = p->next;
    delete p;
  } else { // case of remove anything else
    --index; // head is the first item
    while (index > 1) { // get the node that points to the indexed node
      p = p->next;
      --index;
    }
    ListNode* temp = p->next;
    p->next = p->next->next;
    delete temp;
    temp = nullptr;
  }
  p = nullptr;
  --size;
  return true;
}

void List::print() {
  for (ListNode* p = head; p != nullptr; p = p->next) {
    cout << p->val << " ";
  }
  cout << endl;
}

int main() {
  List list;
  cout << "Is Empty? " << list.empty() << endl;
  cout << "Inserting \'1\' \'2\' \'3\'" << endl;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  cout << "Is Empty? " << list.empty() << endl;
  list.print();
  cout << "Removing second item: " << list.remove(2) << endl;
  list.print();
  cout << "Removing second item: " << list.remove(2) << endl;
  list.print();
  cout << "Inserting \'4\'" << endl;
  list.insert(4);
  list.print();
  cout << "Removing first item: " << list.remove(1) << endl;
  list.print();
  cout << "Removing third item: " << list.remove(3) << endl;
  list.print();

  return 0;
}
