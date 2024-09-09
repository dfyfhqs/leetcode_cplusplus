// @leet start
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, std::greater<int>> queue;
    for (auto& val : nums) {
      queue.push(val);
      if (queue.size() > k) {
        queue.pop();
      }
    }
    return queue.top();
  }
};
// @leet end
