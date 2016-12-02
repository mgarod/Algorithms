void merge(int arr[], int low, int mid, int high) {
  const int aSIZE = (mid - low + 1);
  const int bSIZE = (high - mid);

  std::unique_ptr<int[]> a(new int[aSIZE]);
  std::unique_ptr<int[]> b(new int[bSIZE]);

  for (int i = 0; i < aSIZE; ++i)
    a[i] = arr[low + i];
  for (int i = 0; i < bSIZE; ++i)
    b[i] = arr[(mid + 1) + i];

  int aptr = 0, bptr = 0;
  while (aptr < aSIZE && bptr < bSIZE)
    arr[low++] = (a[aptr] <= b[bptr]) ? a[aptr++] : b[bptr++];
  while (aptr < aSIZE)
    arr[low++] = a[aptr++];
  while (bptr < bSIZE)
    arr[low++] = b[bptr++];
}

void mergesort(int arr[], int lo, int hi) {
  if (lo < hi) {
    int mid = ((hi - lo) >> 1) + lo;
    mergesort(arr, lo, mid);
    mergesort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
  }
}

int main() {
  const int SIZE1 = 14;
  int array1[SIZE1] = {4, 6, 3, -7, 19, 12, 2, 14, 1, 0, -4, 11, 5, 9};

  printArray(array1, SIZE1);
  mergesort(array1, 0, SIZE1-1);
  printArray(array1, SIZE1);
  cout << endl;

  const int SIZE2 = 5;
  int array2[SIZE2] = {4, 6, 3, -7, 19};

  printArray(array2, SIZE2);
  mergesort(array2, 0, SIZE2-1);
  printArray(array2, SIZE2);
  cout << endl;

  const int SIZE3 = 2;
  int array3[SIZE3] = {6, 3};

  printArray(array3, SIZE3);
  mergesort(array3, 0, SIZE3-1);
  printArray(array3, SIZE3);
  cout << endl;

  const int SIZE4 = 1;
  int array4[SIZE4] = {3};

  printArray(array4, SIZE4);
  mergesort(array4, 0, SIZE4-1);
  printArray(array4, SIZE4);
  cout << endl;

  const int SIZE5 = 0;
  int array5[SIZE5] = {};

  printArray(array5, SIZE5);
  mergesort(array5, 0, SIZE5-1);
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