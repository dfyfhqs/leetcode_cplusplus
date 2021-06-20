/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        DFS(res, nums, 0);
        return res;
    }

    void DFS(vector<vector<int>>& result,
                   vector<int>& nums,
                   int pos) {
        if (pos == nums.size()-1) {
            result.emplace_back(nums);
            return;
        } 
        for (auto i = pos; i < nums.size(); ++i) {
            swap(nums[pos], nums[i]);
            DFS(result, nums, pos+1);
            swap(nums[pos], nums[i]);
        }
    }
};
// @lc code=end

