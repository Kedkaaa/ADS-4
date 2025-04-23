// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += (n * (n - 1)) / 2;
        break;
      } else {
          int leftVal = arr[left], leftCount = 0;
          while (left < right && arr[left] == leftVal) {
            ++leftCount;
            ++left;
          }
          int rightVal = arr[right], rightCount = 0;
          while (right >= left && arr[right] == rightVal) {
            ++rightCount;
            --right;
          }
          count += leftCount * rightCount;
        }
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] < target)
        left = mid + 1;
      else {
        right = mid - 1;}
    }
    int lower = left;
    left = i + 1, right = len - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] <= target)
        left = mid + 1;
      else {
        right = mid - 1;}
    }
    int upper = right;
    if (lower <= upper)
      count += (upper - lower + 1);
  }
  return count;
}
