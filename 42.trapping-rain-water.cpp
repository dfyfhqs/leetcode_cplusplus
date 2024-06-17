// @leet start
class Solution {
 public:
  int trap2(vector<int>& height) {
    int result = 0;
    int left = 0, right = height.size() - 1;
    int max_left = height[left];
    int max_right = height[right];
    while (left < right) {
      if (max_left <= max_right) {
        left = left + 1;
        if (left < height.size()) {
          if (height[left] < max_left) {
            result += max_left - height[left];
          } else {
            max_left = height[left];
          }
        }
      } else {
        right = right - 1;
        if (right < height.size()) {
          if (height[right] < max_right) {
            result += max_right - height[right];
          } else {
            max_right = height[right];
          }
        }
      }
    }
    return result;
  }

  // 单调栈
  int trap(vector<int>& height) {
    vector<int> label;
    int result = 0;
    for (auto idx = 0; idx < height.size(); ++idx) {
      int val = height[idx];
      if (label.empty() || val < height[label.back()]) {
        label.push_back(idx);
        continue;
      }
      while (!label.empty() && height[label.back()] <= val) {
        int cur = height[label.back()];
        label.pop_back();
        if (!label.empty()) {
          int left = label.back();
          result += (min(val, height[left]) - cur) * (idx - left - 1);
        }
      }
      label.push_back(idx);
    }
    return result;
  }
};
// @leet end
