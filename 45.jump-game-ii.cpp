// @leet start
#include <vector>

class Solution {
 public:
  // 使用动态规划
  int jump(std::vector<int>& nums) {
    std::vector<int> label(nums.size(), INT_MAX);
    label[0] = 0;
    int result = 0;
    for (auto i = 0; i < nums.size(); ++i) {
      // cout << "i: " << i << " label[i]: " << label[i] << endl;
      int start = i + 1;
      int end = min(i + nums[i], int(nums.size()) - 1);
      int j = start;
      // cout << "start: " << start << " end: " << end << endl;
      for (; j <= end; ++j) {
        label[j] = min(label[i] + 1, label[j]);
      }
    }
    return *label.rbegin();
  }
};
// @leet end
