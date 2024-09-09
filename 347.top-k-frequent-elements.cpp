// @leet start

struct Cmp {
  bool operator()(pair<int, int>& m, pair<int, int>& n) {
    return m.second > n.second;
  }
};

class Solution {
 public:
  static bool cmp(pair<int, int>& m, pair<int, int>& n) {
    return m.second > n.second;
  }

  vector<int> topKFrequent(vector<int>& nums, int k) {
    // priority_queue<std::pair<int, int>, vector<pair<int, int>>,
    // decltype(&cmp)> queue(cmp);
    Cmp cmp;
    priority_queue<std::pair<int, int>, vector<pair<int, int>>, Cmp> queue(cmp);
    std::unordered_map<int, int> label;
    for (auto& val : nums) {
      ++label[val];
    }

    for (auto& val : label) {
      queue.push(val);
      if (queue.size() <= k) {
        continue;
      }
      queue.pop();
    }

    std::vector<int> result;
    while (!queue.empty()) {
      result.push_back(queue.top().first);
      queue.pop();
    }
    return result;
  }
};
// @leet end
