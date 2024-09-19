// @leet start
#include <unordered_map>
class Solution {
 public:
  int climbStairs(int n) { return dfs(n); }
  int dfs(int n) {
    if (n == 0) {
      return 0;
    }
    if (n < 3) {
      return n;
    }
    auto find = label_.find(n);
    if (find != label_.end()) {
      return find->second;
    }
    auto result = dfs(n - 1) + dfs(n - 2);
    label_[n] = result;
    return result;
  }
  std::unordered_map<int, int> label_;
};
// @leet end
