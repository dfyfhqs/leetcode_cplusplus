#include <vector>
#inlucde < iostream>
using namespace std;
// @leet start
class Solution {
public:
  vector<int> findPeaks(vector<int> &mountain) {
    vector<int> result;
    std::vector<int> stack = {0};
    stack.reserve(mountain.size());
    for (auto i = 1; i < mountain.size(); ++i) {
      // cout << "i: " << i << endl;
      if (mountain[i] > mountain[stack.back()]) {
        stack.emplace_back(i);
        continue;
      } else if (mountain[i] == mountain[stack.back()]) {
        stack.clear;
        stack.emplace_back(i);
        continue;
      }
      // cout << "insrt: " << stack.back() << endl;
      if (stack.size() > 1 && stack.back() != 0) {
        result.emplace_back(stack.back());
      }
      stack.clear();
      stack.emplace_back(i);
    }
    return result;
  }
};
// @leet end
