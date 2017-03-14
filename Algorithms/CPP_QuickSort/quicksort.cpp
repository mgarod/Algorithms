#include <iostream>
using namespace std;

void printArray(int arr[], const int SIZE);
void printArray(const std::unique_ptr<int[]>& arr, const int SIZE);
void partition(int a[], int pivotindex, int low, int high);
void quicksort(int arr[], int lo, int hi);

void partition(int a[], int pivotindex, int low, int high) {
  int pivot = a[pivotindex];
  std::swap(a[pivotindex], a[high]);
  int left = low, right = high-1;
  while (left < right) {
    while (a[left] < pivot) ++left;
    while (a[right] > pivot) --right;
    if (left < right) std::swap(a[left++], a[right--]);
  }

  int index_pos = high;
  while (index_pos > 0 && a[index_pos-1] > pivot) {
    a[index_pos] = a[index_pos-1];
    --index_pos;
  }
  a[index_pos] = pivot;

  quicksort(a, low, index_pos-1);
  quicksort(a, index_pos+1, high);
}

void quicksort(int arr[], int lo, int hi) {
  if (lo < hi) {
    int index_of_pivot = ((hi - lo) >> 1) + lo;
    partition(arr, index_of_pivot, lo, hi);
  }
}

int main() {
  const int SIZE1 = 14;
  int array1[SIZE1] = {4, 6, 3, -7, 19, 12, 2, 14, 1, 0, -4, 11, 5, 9};

  printArray(array1, SIZE1);
  quicksort(array1, 0, SIZE1-1);
  printArray(array1, SIZE1);
  cout << endl;

  const int SIZE2 = 5;
  int array2[SIZE2] = {4, 6, 3, -7, 19};

  printArray(array2, SIZE2);
  quicksort(array2, 0, SIZE2-1);
  printArray(array2, SIZE2);
  cout << endl;

  const int SIZE3 = 2;
  int array3[SIZE3] = {6, 3};

  printArray(array3, SIZE3);
  quicksort(array3, 0, SIZE3-1);
  printArray(array3, SIZE3);
  cout << endl;

  const int SIZE4 = 1;
  int array4[SIZE4] = {3};

  printArray(array4, SIZE4);
  quicksort(array4, 0, SIZE4-1);
  printArray(array4, SIZE4);
  cout << endl;

  const int SIZE5 = 0;
  int array5[SIZE5] = {};

  printArray(array5, SIZE5);
  quicksort(array5, 0, SIZE5-1);
  printArray(array5, SIZE5);
  cout << endl;

  return 0;
}



void printArray(int arr[], const int SIZE) {
  cout << "{ ";
  for (int i = 0; i < SIZE; ++i) {
    cout << arr[i];
    if (i != SIZE-1)
      cout << ", ";
  }
  cout << " }" << endl;
}

void printArray(const std::unique_ptr<int[]>& arr, const int SIZE) {
  cout << "{ ";
  for (int i = 0; i < SIZE; ++i) {
    cout << arr[i];
    if (i != SIZE-1)
      cout << ", ";
  }
  cout << " }" << endl;
}