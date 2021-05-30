/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto param = maxWeight(weights);
        int left = param.first, right = param.second + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool canFinish(const vector<int>& weight, int cap, int days) {
        int use_day = 0;
        int res = 0;
        for (auto val : weight) {
            if (val > cap) {
                return false;
            }
            if (res + val > cap) {
                ++use_day;
                res = 0;
            }
            res += val;
        }
        return use_day < days;
    }

    std::pair<int,int> maxWeight(const vector<int>& weight) {
        int res = 0;
        int maxWeight = 0;
        for (auto val : weight) {
            maxWeight = max(maxWeight, val);
            res += val;
        }
        return std::make_pair(maxWeight, res);
    }
};
// @lc code=end

