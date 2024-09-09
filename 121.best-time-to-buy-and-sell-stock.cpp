// @leet start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // 动态规划
    return dynamic(prices);
    // 贪心算法
    // return greedy(prices);
  }

  // 动态规划
  // dp[i][0] 表示第i天持有股票所得现金。
  // dp[i][1] 表示第i天不持有股票所得最多现金
  int dynamic(vector<int>& prices) {
    std::vector<std::array<int, 2>> label(prices.size(), std::array<int, 2>());
    label[0][0] = -prices[0];
    label[0][1] = 0;
    int result = 0;
    for (auto i = 1; i < prices.size(); ++i) {
      label[i][0] = max(label[i - 1][0], -prices[i]);
      label[i][1] = max(0, label[i - 1][0] + prices[i]);
      result = max(result, label[i][1]);
    }
    return result;
  }

  // 贪心算法
  int greedy(vector<int>& prices) {
    vector<int> label;
    int result = 0;
    int m_val = INT_MIN;
    for (auto iter = prices.rbegin(); iter != prices.rend(); ++iter) {
      m_val = max(m_val, *iter);
      result = max(result, m_val - *iter);
    }
    return result;
  }

  int result_ = INT_MIN;
};
// @leet end
