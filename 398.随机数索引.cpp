/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& nums_;
    Solution(vector<int>& nums) : nums_(nums) {
    
    }
    
    int pick(int target) {
        size_t cnt = 0;
        int index = INT_MIN;
        for (auto i = 0; i < nums_.size(); ++i) {
            if (nums_[i] == target) {
                ++cnt;
                if (random() % cnt == 0) {
                    index = i;
                }
            }
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

