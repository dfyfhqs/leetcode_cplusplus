/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::stack<int> stack;
        std::map<int, int> result_map;
        for (auto val : nums2) {
            result_map[val] = -1;
        }
        for (auto val : nums2) {
            while(!stack.empty() && stack.top() < val) {
                result_map[stack.top()] = val;
                stack.pop();
            }
            stack.push(val);
        }
        for (auto i = 0; i < nums1.size(); ++i) {
          nums1[i] = result_map[nums1[i]];
        }
        return nums1;
    }
};
// @lc code=end

