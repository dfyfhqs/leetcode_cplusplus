// @leet start
#include <climits>
#include <cstdlib>
#include <unordered_map>
class Solution {
 public:
  int numSquares(int n) {
    label_.resize(n + 1, INT_MAX);
    label_[0] = 0;
    label_[1] = 1;
    for (auto i = 2; i <= n; ++i) {
      label_[i] = i;
      for (auto j = 2; i - j * j >= 0; ++j) {
        label_[i] = min(label_[i], label_[i - j * j] + 1);
      }
    }
    return label_[n];
  }

  // int numSquares_failed(int n) {
  //   // label_.resize(n + 1, INT_MAX);
  //   // label_[0] = 0;
  //   // label_[1] = 1;
  //   // for (auto i = 2; i < n; ++i) {
  //   //   int cur = i * i;
  //   //   if (cur <= n) {
  //   //     label_[cur] = 1;
  //   //   } else {
  //   //     break;
  //   //   }
  //   // }
  //   // return deep(n, 0);
  // }

  // int deep(int n, int deepth) {
  //   if (label_[n] != INT_MAX) {
  //     return label_[n];
  //   }
  //   // std::string pre = "";
  //   // for (int i = 0; i < deepth; ++i) {
  //   //   pre += "  ";
  //   // }
  //   //  cout << pre << " n: " << n << endl;
  //   for (auto i = n; i > 0; --i) {
  //     if (label_[i] == INT_MAX) {
  //       continue;
  //     }
  //     int count = n / i;
  //     int rest = n % i;
  //     if (rest == 0) {
  //       label_[n] = min(label_[n], count * label_[i]);
  //       return label_[n];
  //     }
  //     for (int j = count; j > -1; --j) {
  //       int tmp = deep(n - j * i, deepth + 1);
  //       if (tmp == 0) {
  //         continue;
  //       }
  //       label_[n] = min(label_[n], j * label_[i] + tmp);
  //     }
  //   }
  //   return label_[n];
  // }
  std::vector<int> label_;
};
// @leet end
