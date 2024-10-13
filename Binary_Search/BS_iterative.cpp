int binarySearch(vector<int>array,int x) {
  int low=0,high=array.size()-1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (x == array[mid]) return mid;
    if (x > array[mid])  low = mid + 1;
    else high = mid - 1;
  }

  return -1;
}
