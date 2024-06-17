// @leet start
class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    int mount = row * col;
    int num_target = 0;
    int result = 0;
    int time = 0;
    queue<tuple<int, int>> label;
    for (auto i = 0; i < row; ++i) {
      for (auto j = 0; j < col; ++j) {
        if (grid[i][j] == 1) {
          ++num_target;
        } else if (grid[i][j] == 2) {
          label.emplace(i, j);
        }
      }
    }

    if (num_target == 0) return 0;

    std::vector<tuple<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    while (!label.empty()) {
      ++time;
      int size = label.size();
      for (auto i = 0; i < size; ++i) {
        auto [x, y] = label.front();
        label.pop();
        for (auto& [dirx, diry] : dir) {
          int tempx = x + dirx;
          int tempy = y + diry;
          if (tempx < 0 || tempx >= row || tempy < 0 || tempy >= col) {
            continue;
          }
          if (grid[tempx][tempy] != 1) {
            continue;
          }
          ++result;
          grid[tempx][tempy] = 2;
          label.emplace(tempx, tempy);
        }
      }
      if (num_target == result) {
        return time;
      }
    }
    return (result == num_target) ? time : -1;
  }
};
// @leet end
