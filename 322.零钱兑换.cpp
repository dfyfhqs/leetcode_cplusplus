/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount);
    }

    int dp(const vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }
        int res = INT_MAX;
        for (auto val : coins) {
            auto subproblem = dp(coins, amount - val);
            if (subproblem == -1) {
                continue;
            }
            res = min(res, subproblem + 1);
        }
        if (res < INT_MAX) {
            return res;
        }
        return -1;

    }
};
// @lc code=end

