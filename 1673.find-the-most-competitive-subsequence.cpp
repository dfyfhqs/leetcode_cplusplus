#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @leet start
// class Solution {
// public:
//   std::string DumpVec(const std::vector<int> &vec) {
//     std::string result;
//     std::for_each(vec.begin(), vec.end(),
//                   [&](int val) { result += std::to_string(val) + ","; });
//     return result;
//   }
//
//   vector<int> mostCompetitive(vector<int> &nums, int k) {
//     return mostCompetitive(nums, 0, k);
//   }
//
//   vector<int> mostCompetitive(const std::vector<int> &nums, int start, int k)
//   {
//     if (k <= 0 || nums.size() - start < k) {
//       return vector<int>();
//     }
//
//     auto &&vec1 = mostCompetitive(nums, start + 1, k);
//     auto &&vec2 = mostCompetitive(nums, start + 1, k - 1);
//     // cout << "start: " << start << " k: " << k << endl;
//     vec2.insert(vec2.begin(), nums[start]);
//     // cout << "vec1: " << DumpVec(vec1) << endl;
//     // cout << "vec2: " << DumpVec(vec2) << endl;
//     if (vec2.size() != k && vec1.size() != k) {
//       return vector<int>();
//     }
//     if (vec1.size() != k && vec2.size() == k) {
//       return vec2;
//     }
//     if (vec2.size() != k && vec1.size() == k) {
//       return vec1;
//     }
//
//     for (int i = 0; i < k; ++i) {
//       if (vec1[i] < vec2[i]) {
//         return vec1;
//       }
//     }
//     return vec2;
//   }
// };

class Solution {
public:
  std::string DumpVec(const std::vector<int> &vec) {
    std::string result;
    std::for_each(vec.begin(), vec.end(),
                  [&](int val) { result += std::to_string(val) + ","; });
    return result;
  }

  vector<int> mostCompetitive(vector<int> &nums, int k) {
    vector<int> res;
    int n = nums.size();
    for (auto i = 0; i < n; ++i) {
      while (!res.empty() && n - i + res.size() > k && res.back() > nums[i]) {
        res.pop_back();
      }
      res.push_back(nums[i]);
    }
    res.resize(k);
    return res;
  }
};
// @leet end
