/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        auto range = GetRange(nums);
        size_t left = range.first;
        size_t right = range.second;
        if (m == nums.size()) {
            return left;
        } else if (m == 1) {
            return right;
        }
        while(left < right) {
            size_t mid = left + (right - left) / 2;
            size_t curr_bagsize = 0, curr_m = 1;
            for (auto n : nums) {
                if (curr_bagsize + n > mid) {
                    ++curr_m;
                    curr_bagsize = 0;
                }
                curr_bagsize += n;
            }
            if (curr_m > m) {
                left = mid + 1;
            } else {
                right = mid;
            }

        }
        return left;
    }

    std::pair<size_t,size_t> GetRange(const vector<int>& nums) {
        size_t left = 0, right = 0;

        for (auto val : nums) {
            if (val > left) {
                left = val;
            }
            right += val;
        }
        return make_pair(left, right);
    }
};
// @lc code=end

