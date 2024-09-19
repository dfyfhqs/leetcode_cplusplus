// @leet start
#include <unordered_map>
#include <unordered_set>
class Solution {
 public:
  vector<int> partitionLabels(string s) {
    // 分区间
    unordered_map<char, int> label;
    // 天然按照first 从小到大的顺序
    vector<pair<int, int>> interval;
    auto length = s.size();
    for (auto i = 0; i < length; ++i) {
      auto c = s[i];
      auto find = label.find(c);
      if (find == label.end()) {
        interval.push_back({i, i});
        label[c] = interval.size() - 1;
      } else {
        interval[find->second].second = i;
      }
    }

    vector<int> result;
    pair<int, int> cur{0, 0};
    // 区间合并
    for (auto& [first, second] : interval) {
      // cout << "first: " << first << " second: " << second
      //      << " cur: " << cur.first << " , " << cur.second << endl;
      if (first <= cur.second && second > cur.second) {
        // cout << "first" << endl;
        cur.second = second;
      } else if (second <= cur.second) {
        // cout << "second" << endl;
        continue;
      } else if (first > cur.second) {
        // cout << "third" << endl;
        // cout << "cur: " << cur.first << " second: " << cur.second << endl;
        result.emplace_back(cur.second - cur.first + 1);
        cur.first = first;
        cur.second = second;
      }
      // cout << "adjust cur: " << cur.first << ", " << cur.second << endl;
    }
    result.emplace_back(cur.second - cur.first + 1);
    return result;
  }
};
// @leet end
