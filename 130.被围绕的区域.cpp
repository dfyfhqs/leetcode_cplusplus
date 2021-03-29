/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        normalSolve(board);
    }

    bool checkIsConnect(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'X') {
            return false;
        }
        int row = board.size();
        int col = board[0].size();
        std::vector<std::tuple<int,int>>d;
        d.emplace_back(std::make_tuple(1,0));
        d.emplace_back(std::make_tuple(0,1));
        d.emplace_back(std::make_tuple(-1,0));
        d.emplace_back(std::make_tuple(0,-1));
        std::stack<std::tuple<int, int>> label;
        label.push(std::make_tuple(i,j));
        while(!label.empty()) {
            int curRow = std::get<0>(label.top());
            int curCol = std::get<1>(label.top());
            board[curRow][curCol] = '#';
            label.pop();
            for(auto k = 0; k < d.size(); ++k) {
                int tmpRow = curRow + std::get<0>(d[k]);
                int tmpCol = curCol + std::get<1>(d[k]);
                if (tmpRow < 0 || tmpRow >= row || tmpCol < 0 || tmpCol >= col) {
                    continue;
                }
                if (board[tmpRow][tmpCol] == 'O') {
                    label.push(std::make_tuple(tmpRow, tmpCol));
                }
            }
        }
        return true;
    }

    void normalSolve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();
        if (col == 0) {
            return;
        }
        for (auto i = 0; i < row; ++i) {
            checkIsConnect(board, i, 0);
            checkIsConnect(board, i, col-1);
        }
        for (auto i = 0; i < col; ++i) {
            checkIsConnect(board, 0, i);
            checkIsConnect(board, row-1, i);
        }
        for (auto i = 0; i < row; ++i) {
            for (auto j = 0; j < col; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

};
// @lc code=end

