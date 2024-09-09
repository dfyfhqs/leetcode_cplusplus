// @leet start
// 2,1,5,6,2,3
// 3,1,3
// 2,4
// 5,4,2,1
// 420325

#include <vector>

// 所以单调栈可以找到边界,递增则找到小于这个数的边界,递减则找到大于这个数的边界
class Solution {
 public:
  int largestRectangleArea(std::vector<int>& heights) {
    vector<int> label;
    heights.insert(heights.begin(), INT_MIN);
    heights.push_back(INT_MIN);
    int result = 0;

    for (auto i = 0; i < heights.size(); ++i) {
      auto cur = heights[i];
      if (label.empty()) {
        label.push_back(i);
        continue;
      }

      if (cur < heights[*label.rbegin()]) {
        size_t j = 0;
        // cout << endl;
        // cout << endl;
        // cout << "i: " << i << " cur: " << cur << endl;
        int start = 0;
        for (j = 1; j < label.size(); ++j) {
          if (cur < heights[label[j]]) {
            if (start == 0) {
              start = j;
            }
            // cout << " j: " << j << " heights[label[j]]: " <<
            // heights[label[j]]
            //      << " label.rbegin: " << *label.rbegin();
            int tmp = heights[label[j]] * (*label.rbegin() - label[j - 1]);
            // cout << " tmp: " << tmp << endl;
            result = max(result, tmp);
          } else {
            continue;
          }
        }
        label.erase(label.begin() + start, label.begin() + j);
      }
      label.push_back(i);
    }
    return result;

    return result;
  }
};
// @leet end
