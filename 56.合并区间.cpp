/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (49.36%)
 * Likes:    1982
 * Dislikes: 0
 * Total Accepted:    671.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if (intervals.empty()) {
        return vector<vector<int>>();
      }
      std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
      });

      vector<vector<int>> result;
      vector<int> cur = intervals[0];
      for (int i = 1; i < intervals.size(); ++i) {
        auto& val = intervals[i];
        // 两个区间相交
        if (val[0] >= cur[0]  && val[0] <= cur[1]) {
          cur[0] = min(val[0], cur[0]);
          cur[1] = max(val[1], cur[1]);
          std::cout << " inter " << std::endl;
        } else {
          result.emplace_back(std::move(cur));
          cur = std::move(val);
        }
      }
      result.emplace_back(std::move(cur));
      return result;
    }
};
// @lc code=end

