/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 *
 * https://leetcode.cn/problems/remove-covered-intervals/description/
 *
 * algorithms
 * Medium (56.00%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    28.3K
 * Total Submissions: 50.6K
 * Testcase Example:  '[[1,4],[3,6],[2,8]]'
 *
 * 给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
 * 
 * 只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。
 * 
 * 在完成所有删除操作后，请你返回列表中剩余区间的数目。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：intervals = [[1,4],[3,6],[2,8]]
 * 输出：2
 * 解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
 * 
 * 
 * 
 * 
 * 提示：​​​​​​
 * 
 * 
 * 1 <= intervals.length <= 1000
 * 0 <= intervals[i][0] < intervals[i][1] <= 10^5
 * 对于所有的 i != j：intervals[i] != intervals[j]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
      if (intervals.empty()) return 0;
      // 从小到大排序
      std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
      });
      //for (auto& val : intervals) {
      //  std::cout << " " << val[0] << "," << val[1] << std::endl;
      //}

      int result = 1;
      vector<int> range = intervals[0];
      for (int i = 1; i < intervals.size(); ++i) {
        auto& val = intervals[i];
        // 被覆盖
        if (val[0] >= range[0] && val[1] <= range[1]) {
          continue;
        } else {
          range = val;
          ++result;
        }
      }
      return result;
    }
};
// @lc code=end

