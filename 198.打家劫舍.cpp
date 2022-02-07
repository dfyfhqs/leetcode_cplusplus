/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include <​unordered_map>
#include <iostream>
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        result_[-1] = 0;
        result_[0] = nums[0];
        for (auto i = 1; i < nums.size(); ++i) {
            result_[i] = std::max(result_[i-2]+nums[i], result_[i-1]);
        }
        return result_[nums.size()-1];
    }

    std::unordered_map<int, int> result_;
};

//int main() {
//    Solution so;
//    std::vector<int> test = {1,2,3,1};
//    std::cout << so.rob(test) << std::endl;
//}
// @lc code=end

