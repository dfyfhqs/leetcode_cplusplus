/*
 * @Author: stone stone
 * @Date: 2023-08-23 01:00:03
 * @LastEditors: stone stone
 * @LastEditTime: 2023-08-23 22:55:00
 * @FilePath: /leetcode_cplusplus/1094.拼车.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 *
 * https://leetcode.cn/problems/car-pooling/description/
 *
 * algorithms
 * Medium (51.58%)
 * Likes:    268
 * Dislikes: 0
 * Total Accepted:    77K
 * Total Submissions: 149.3K
 * Testcase Example:  '[[2,1,5],[3,3,7]]\n4'
 *
 * 车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）
 * 
 * 给定整数 capacity 和一个数组 trips ,  trip[i] = [numPassengersi, fromi, toi] 表示第 i
 * 次旅行有 numPassengersi 乘客，接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。
 * 
 * 当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：trips = [[2,1,5],[3,3,7]], capacity = 4
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：trips = [[2,1,5],[3,3,7]], capacity = 5
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= trips.length <= 1000
 * trips[i].length == 3
 * 1 <= numPassengersi <= 100
 * 0 <= fromi < toi <= 1000
 * 1 <= capacity <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

      vector<int> label(1001, 0);
      int left = INT_MAX, right = INT_MIN;
      for (auto& trip : trips) {
        if (trip[1] == trip[2]) continue;
        left = min(left, trip[1]);
        right = max(right, trip[2]);
        label[trip[1]] += trip[0];
        label[trip[2]] -= trip[0];
        if (label[trip[1]] > capacity) {
          return false;
        }
      }

      int cur = 0;
      for (int i = left; i <= right; ++i) {
        cur += label[i];
        if (cur > capacity) {
          return false;
        }
      }
      return true;
    }
};
// @lc code=end

