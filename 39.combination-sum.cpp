// @leet start
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> result;
    std::sort(candidates.begin(), candidates.end());
    help(candidates, result, 0, target);
    return result_vec_;
  }

  void help(vector<int>& candidates, vector<int>& result, int start,
            int target) {
    if (target == 0) {
      result_vec_.push_back(result);
      return;
    }
    if (start >= candidates.size()) {
      return;
    }
    if (target < candidates[start]) {
      return;
    }
    int size = target / candidates[start];
    int curtarget = target;
    for (auto i = 0; i <= size; ++i) {
      if (i > 0) {
        result.push_back(candidates[start]);
        curtarget -= candidates[start];
      }
      help(candidates, result, start + 1, curtarget);
    }

    for (auto i = 0; i < size; ++i) {
      result.pop_back();
    }
  }

  vector<vector<int>> result_vec_;
};
// @leet end
