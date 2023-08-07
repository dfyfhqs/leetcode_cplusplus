/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.69%)
 * Likes:    1413
 * Dislikes: 0
 * Total Accepted:    448.9K
 * Total Submissions: 752.8K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 
 * 注意：解集不能包含重复的组合。 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 示例 2:
 * 
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      std::sort(candidates.begin(), candidates.end(), less<int>());
      dp(candidates, target, 0);
      return finalResult_;
    }

    void dp(vector<int>& candiHdates, int target , int index) {
      // std::cout << "begin not used: target: " << target << " index: " << index << std::endl;
      //std::cout << "target: " << target << " index: " << index << std::endl;
      std::string result, used;

      std::for_each(result_.begin(), result_.end(), [&](auto& val) {
        result += "," + std::to_string(val);  
      });
      //std::cout << result << std::endl;
      if (target == 0) {
        finalResult_.push_back(result_);
        return;
      }

      if (index >= candidates.size()) {
        return;
      }

      if (target < candidates[index]) {
        return;
      }

      if (index > 0 && candidates[index] == candidates[index - 1] && (used_[index-1] == false)) {
        used_.emplace_back(false);
        dp(candidates, target, index + 1);
        used_.pop_back();
        return;
      }
      // used
      used_.emplace_back(true);
      result_.emplace_back(candidates[index]);
      dp(candidates, target - candidates[index], index + 1);
      used_.pop_back();
      result_.pop_back();
      // not use
      //std::cout << "not used: target: " << target << " index: " << index+1 << std::endl;
      used_.emplace_back(false);
      dp(candidates, target, index + 1);
      used_.pop_back();
    }

    vector<int> used_;
    vector<int> result_;
    vector<vector<int>> finalResult_;
};
// @lc code=end

