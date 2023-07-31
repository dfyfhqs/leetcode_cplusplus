// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <stack>
#include <vector>

// 1. 单调栈 2. 双指针
// @lc code=start
class Solution {
public:

    int trap(vector<int>& height) {
      int left = 0, right = height.size() - 1, result = 0;
      int leftMax = height[left], rightMax = height[right];
      while (left <= right) {
        if (leftMax < rightMax) {
          if (height[left] < leftMax) {
            result += leftMax - height[left];
          } else {
            leftMax = height[left];
          }
          ++left;
        } else {
          if (height[right] < rightMax) {
            result += rightMax - height[right];
          } else {
            rightMax = height[right];
          }
          --right;
        }
      }
      return result;
    }
    
    int trapstack(vector<int>& height) {
      int result = 0;
      std::vector<int> stack;
      for (size_t i = 0; i < height.size(); ++i) {
        std::cout << "i: " << i << std::endl;
        if (stack.empty()) {
          stack.push_back(i);
          continue;
        }

        if (height[stack.back()] >= height[i]) {
          stack.push_back(i);
          continue;
        }

        while (!stack.empty() && height[stack.back()] < height[i]) {
          int curheight = height[stack.back()];
          stack.pop_back();
          if (stack.empty()) {
            break;
          }
          int left = height[stack.back()];
          std::cout << "left: " << left << " stack.back: " << stack.back() << std::endl;
          result += (min(left, height[i]) - curheight) * (i - stack.back() - 1);
        }
        stack.emplace_back(i);
        std::cout << "  result: " << result << std::endl;
      }
      return result;
    }
};
// @lc code=end

