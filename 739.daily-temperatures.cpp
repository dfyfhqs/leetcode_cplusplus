// @leet start
#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    // 使用单调栈解决
    std::stack<int> idx;
    vector<int> result(temperatures.size(), 0);
    for (auto i = 0; i < temperatures.size(); ++i) {
      if (idx.empty()) {
        idx.push(i);
        continue;
      }
      while (!idx.empty()) {
        auto top_idx = idx.top();
        if (temperatures[top_idx] >= temperatures[i]) {
          break;
        } else {
          idx.pop();
          result[top_idx] = i - top_idx;
        }
      }
      idx.push(i);
    }
    return result;
  }
};
// @leet end
