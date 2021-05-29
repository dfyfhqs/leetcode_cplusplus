/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> st;
        std::vector<int> res;
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!st.empty() && i - st.back() < k && nums[st.back()] < nums[i]) {
                st.pop_back();
            }
            st.emplace_back(i);
            if (i < k-1) {
                continue;
            }
            if (i - st.front() >= k) {
                st.pop_front();
            }
            res.emplace_back(nums[st.front()]);
        }
        return res;
    }
};
// @lc code=end

