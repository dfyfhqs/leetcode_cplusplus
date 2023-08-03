/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      std::sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
      });

      // for (auto& val : envelopes) {
      //   std::cout << val[0] << "," << val[1] << std::endl;
      // }

      std::vector<int> dp;
      dp.reserve(envelopes.size());
      for (const auto& val : envelopes) {
        dp.push_back(val[1]);
      }

      return lenghtOfLis(dp);
    }

    // 二分法查找最长子序列， 参考300
    int lenghtOfLis(const std::vector<int>& dp) {
      std::vector<int> label(dp.size(), INT_MAX);
      int size = 0;
      label[0] = dp[0];
      for (auto i = 1; i < dp.size(); ++i) {
        auto val = dp[i];
        int left = 0, right = size;
        while (left <= right) {
          int mid = left + (right - left) / 2;
          if (label[mid] < val) {
            left = mid + 1;
          } else {
            right = mid -1;
          }
        }
        // std::cout << left << "," << size << "," << val << std::endl;
        if (left <= size && label[left] >= val) {
          label[left] = val;
        } else {
          size += 1;
          label[size] = val;
        }
        // std::cout << left << "," << size << std::endl;
      }
      return size + 1;
    }
};
// @lc code=end

