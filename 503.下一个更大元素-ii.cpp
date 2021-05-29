/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::vector<int> raw_data = nums;
        raw_data.insert(raw_data.begin(), nums.begin(), nums.end());
        vector<int> res(nums.size(), -1);
        stack<int> st;
        for (auto i = 0; i < raw_data.size(); ++i) {
            int ele = raw_data[i];
            int temp_i = i >= res.size() ? i - res.size() : i;
            while (!st.empty() && ele > nums[st.top()]) {
                res[st.top()] = ele;
                st.pop();
            }
            if (res[temp_i] == -1) {
                st.push(temp_i);
            }
        }
        return res;

    }
};
// @lc code=end

