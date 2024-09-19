// @leet start
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) {
      return 0;
    }
    std::stable_sort(coins.begin(), coins.end(), std::less<int>());
    vector<int> label(amount + 1, INT_MAX);
    for (int i = 1; i <= amount; ++i) {
      // cout << "i " << i << endl;
      for (auto& val : coins) {
        if (val > i) {
          break;
        }
        if (i == val) {
          label[i] = 1;
          // cout << "  i: " << i << " label[i]: " << label[i] << endl;
          break;
        }
        if (label[i - val] == INT_MAX) {
          continue;
        }
        label[i] = min(label[i], 1 + label[i - val]);

        // cout << "i: " << i << " label[i]: " << label[i] << endl;
      }
    }
    if (label[amount] == INT_MAX) {
      return -1;
    }
    return label[amount];
  }
};

// @leet end
