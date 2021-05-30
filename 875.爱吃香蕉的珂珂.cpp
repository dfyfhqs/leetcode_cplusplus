/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = getMax(piles) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (CanFinish(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool CanFinish(const vector<int>& piles, int speed, int h) {
        int time = 0;
        for (auto val : piles) {
            time += timeOf(val, speed);
        }
        return time <= h;
    }

    int timeOf(int n, int speed) {
        return n/speed + ((n % speed >0) ? 1 : 0);
    }

    int getMax(const vector<int>& piles) {
        int res = 0;
        for (auto val : piles) {
            res = max(res, val);
        }
        return res;
    }
};
// @lc code=end

