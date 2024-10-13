int binarySearch(vector<int>array, int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    if (x == array[mid])  return mid;
    if (x > array[mid])  return binarySearch(array, x, mid + 1, high);
    else return binarySearch(array, x, low, mid - 1);
  }

  return -1;
}
