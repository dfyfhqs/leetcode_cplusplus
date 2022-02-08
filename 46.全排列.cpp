/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    
   vector<vector<int>> permute(vector<int>& nums) {
       list<int> singleResult;
       BFS(nums, singleResult);
       return result;
   }

   void BFS(const vector<int>& nums, list<int>& singleResult) {
       int size= nums.size();
       for (auto val : nums) {
           // 由于不包含重复数字因此可以怎么判断
           if (std::find(singleResult.begin(), singleResult.end(), val) != singleResult.end()) {
               continue;
           }
           singleResult.push_back(val);
           if (singleResult.size() == size) {
               result.emplace_back(singleResult.begin(), singleResult.end());
           } else {
            BFS(nums, singleResult);
           }
           singleResult.pop_back();
       }
   }
public:
    vector<vector<int>> result;
   // vector<vector<int>> permute(vector<int>& nums) {
   //     vector<vector<int>>res;
   //     DFS(res, nums, 0);
   //     return res;
   // }

   // void DFS(vector<vector<int>>& result,
   //                vector<int>& nums,
   //                int pos) {
   //     if (pos == nums.size()-1) {
   //         result.emplace_back(nums);
   //         return;
   //     } 
   //     for (auto i = pos; i < nums.size(); ++i) {
   //         swap(nums[pos], nums[i]);
   //         DFS(result, nums, pos+1);
   //         swap(nums[pos], nums[i]);
   //     }
   // }



};
// @lc code=end

