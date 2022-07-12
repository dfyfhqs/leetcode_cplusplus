/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
      sum_.reserve(nums.size() + 1);
      sum_.shrink_to_fit();
      int nums_sum = 0;
      sum_.push_back(nums_sum);
      for (auto val : nums) {
        nums_sum += val;
        sum_.push_back(nums_sum);
      }
    }
    
    int sumRange(int left, int right) {
      return sum_[right+1] - sum_[left];
    }

    vector<int> sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

