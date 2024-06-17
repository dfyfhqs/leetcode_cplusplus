// @leet start
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '0') {
          continue;
        }
        cout << "i: " << i << " j: " << j << endl;
        ++result;
        rend(grid, i, j);
      }
    }
    return result;
  }

  void rend(vector<vector<char>>& grid, int cur_x, int cur_y) {
    stack<tuple<int, int>> label;
    int row = grid.size(), col = grid[0].size();
    std::vector<tuple<int, int>> range = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    label.push(tuple{cur_x, cur_y});
    while (!label.empty()) {
      auto [x, y] = label.top();
      label.pop();
      grid[x][y] = '0';
      for (auto [range_x, range_y] : range) {
        auto tempx = x + range_x;
        auto tempy = y + range_y;
        if (tempx > -1 && tempy > -1 && tempx < row && tempy < col &&
            grid[tempx][tempy] == '1') {
          label.push(tuple{tempx, tempy});
        }
      }
    }
  }
};

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    stack<pair<int, int>> label;
    int row = grid.size(), col = grid[0].size();
    for (auto i = 0; i < row; ++i) {
      for (auto j = 0; j < col; ++j) {
        if (grid[i][j] == '0') {
          continue;
        }
        // cout << "i: " << i << " j: " << j << " value: " << grid[i][j] <<
        // endl;
        result += 1;
        label.push(make_pair(i, j));
        // cout << "result: " << result << endl;
        while (!label.empty()) {
          auto site = label.top();
          // cout << "x: " << site.first << " y: " << site.second << endl;
          label.pop();
          grid[site.first][site.second] = '0';
          if (site.first + 1 < row &&
              grid[site.first + 1][site.second] == '1') {
            label.push(make_pair(site.first + 1, site.second));
          }
          if (site.second + 1 < col &&
              grid[site.first][site.second + 1] == '1') {
            label.push(make_pair(site.first, site.second + 1));
          }
          if (site.first - 1 > -1 && grid[site.first - 1][site.second] == '1') {
            label.push(make_pair(site.first - 1, site.second));
          }
          if (site.second - 1 > -1 &&
              grid[site.first][site.second - 1] == '1') {
            label.push(make_pair(site.first, site.second - 1));
          }
        }
      }
    }
    return result;
  }
};

// @leet end
