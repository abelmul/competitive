#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void swap_till(vector<int> &nums, int &next_swap, int number) {
    auto size = nums.size();

    for (int i = next_swap; i < size; ++i) {
      if (nums[i] == number) {
        swap(nums[next_swap], nums[i]);
        ++next_swap;
      }
    }
  }
  void sortColors(vector<int> &nums) {
    int next_swap = 0;

    swap_till(nums, next_swap, 0);
    swap_till(nums, next_swap, 1);
    // swap_till(nums, next_swap, 2);
  }
};
