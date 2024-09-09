// @leet start
#include <vector>
class Solution {
 public:
  int maxArea(vector<int>& height) { return maxAreaPointer(height); }

  // 双指针
  int maxAreaPointer(std::vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int result = 0;
    while (left <= right) {
      int h = 0;
      if (height[left] < height[right]) {
        h = height[left++];
      } else {
        h = height[right--];
      }
      result = max(result, h * (right - left + 1));
    }
    return result;
  }
};
// @leet end
