// @leet start
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    result_.emplace_back(vector<int>());
    // std::sort(nums.begin(), nums.end());
    help(nums, 0);
    return result_;
  }

  void help(vector<int>& nums, int start) {
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // cout << "#####" << endl;
    // for (auto& val : nums) {
    //   cout << "vec: " << val << endl;
    // }
    // cout << "start: " << start << endl;
    if (start == nums.size() - 1) {
      if (start > 0 && nums[start] < nums[start - 1]) {
        return;
      }
      result_.emplace_back(nums);
      return;
    }
    for (auto i = start; i < nums.size(); ++i) {
      if (start > 0 && nums[i] < nums[start - 1]) {
        continue;
      }
      swap(nums[start], nums[i]);
      result_.emplace_back(nums.begin(), nums.begin() + start + 1);
      help(nums, start + 1);
      swap(nums[i], nums[start]);
    }
    // cout << "#####" << endl;
  }

  vector<vector<int>> result_;
};
// @leet end
