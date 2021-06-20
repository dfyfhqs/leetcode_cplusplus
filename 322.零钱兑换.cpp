/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> amount_map_;
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount);
    }

    int dp(const vector<int>& coins, int amount) {
        auto findIter = amount_map_.find(amount);
        if (findIter != amount_map_.end()) {
            return findIter->second;
        }
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
        auto result = res;
        if (res == INT_MAX) {
            result = -1;
        }
        amount_map_[amount] = result;
        return result;

    }
};
// @lc code=end

