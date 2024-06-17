// @leet start
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    help(nums, 0);
    return result_;
  }

  void help(vector<int>& nums, int start) {
    if (start == nums.size() - 1) {
      result_.push_back(nums);
      return;
    }

    for (int i = start; i < nums.size(); ++i) {
      swap(nums[start], nums[i]);
      help(nums, start + 1);
      swap(nums[i], nums[start]);
    }
  }

  vector<vector<int>> result_;
};
// @leet end
