#include <iostream>

void modify(int* arr, int size) {
  arr[0] = 9;
  arr = new int[size]{1, 2};
}

int main() {
  int* nums = new int[3]{5, 6, 7};
  modify(nums, 4);
  std::cout << nums[0] << nums[1];
  delete[] nums;
  return 0;
}
