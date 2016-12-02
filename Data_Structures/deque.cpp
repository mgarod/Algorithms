#include <iostream>
using namespace std;

template <typename T>
struct Node {
  Node() : data(), next(nullptr), prev(nullptr) { };
  Node(T d) : data(d), next(nullptr), prev(nullptr) { };
  
  T data;
  Node<T>* prev;
  Node<T>* next;
};

template <typename T>
class Deque {
 public:
  Deque() : count(0), head(nullptr) { };
  const int size() const { return count; };
  const bool empty() const { return count == 0; };
  void push_front(T d);
  bool pop_front();
  void push_back(T d);
  bool pop_back();
  bool insert(T d, size_t index);
  bool remove(T d);
  bool removeAll(T d);

  void printForward() const;
  void printBackward() const;

 private:
  Node<T>* head;
  Node<T>* tail;
  size_t count;
};

template <typename T>
void Deque<T>::push_front(T d) {
  Node<T>* node = new Node<T>(d);
  if (count == 0) {
    head = node;
    tail = node;
    ++count;
    return;
  }

  head->prev = node;
  node->next = head;
  head = node;
  ++count;
}

template <typename T>
bool Deque<T>::pop_front() {
  if (count == 0)
    return false;

  Node<T>* temp = head;
  head = head->next;
  head->prev = nullptr;
  delete temp;
  --count;
  return true;
}

template <typename T>
void Deque<T>::push_back(T d) {
  Node<T>* node = new Node<T>(d);
  if (count == 0) {
    head = node;
    tail = node;
    ++count;
    return;
  }
  
  tail->next = node;
  node->prev = tail;
  tail = node;
  ++count;
}

template <typename T>
bool Deque<T>::pop_back() {
  if (count == 0)
    return false;

  Node<T>* temp = tail;
  tail = tail->prev;
  tail->next = nullptr;
  delete temp;
  --count;
  return true;
}

template <typename T>
bool Deque<T>::insert(T d, size_t index) {
  if (index > count || index < 0) { // invalid index
    return false;
  } else if (count == 0) { // empty list
    push_front(d);
  } else if (index == 0) { // insert new head
    push_front(d);
  } else if (index == count) { // insert new tail
    push_back(d);
  }
  else {
    Node<T>* cur = head;
    for (int i = 1; i < index; ++i) { cur = cur->next; }
    Node<T>* node = new Node<T>(d);
    node->next = cur->next;
    node->prev = cur;
    node->next->prev = node;
    cur->next = node;
    ++count;
  }
  return true;
}

template <typename T>
bool Deque<T>::remove(T d) {
  for (Node<T>* cur = head; cur != nullptr; cur = cur->next) {
    if (cur->data == d) {
      if (cur->prev == nullptr) {
        head = cur->next;
      } else {
        cur->prev->next = cur->next;
      }
      if (cur->next == nullptr) {
        tail = cur->prev;
      } else {
        cur->next->prev = cur->prev;
      }
      delete cur;
      --count;
      return true;
    }
  }
  return false;
}

template <typename T>
bool Deque<T>::removeAll(T d) {
  bool deleted_one = false;
  while (remove(d)) {
    deleted_one = true;
  }
  return deleted_one;
}

template <typename T>
void Deque<T>::printForward() const {
  for (Node<T>* cur = head; cur != nullptr; cur = cur->next)
    cout << cur->data << " ";
  cout << endl;
}

template <typename T>
void Deque<T>::printBackward() const {
  for (Node<T>* cur = tail; cur != nullptr; cur = cur->prev)
    cout << cur->data << " ";
  cout << endl;
}

int main() {

  Deque<int> deque;
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);

  deque.insert(6, 0);
  deque.printForward();
  deque.removeAll(6);

  deque.insert(6, 1);
  deque.printForward();
  deque.removeAll(6);
  
  deque.insert(6, 2);
  deque.printForward();
  deque.removeAll(6);
  
  deque.insert(6, 3);
  deque.printForward();
  deque.removeAll(6);

  deque.insert(6, 4);
  deque.printForward();
  deque.removeAll(6);

  deque.insert(6, 5);
  deque.printForward();
  deque.removeAll(6);

  deque.insert(6, 6);
  deque.printForward();
  deque.removeAll(6);
  

  return 0;
}