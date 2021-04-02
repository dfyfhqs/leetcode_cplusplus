/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */




// @lc code=start


// 并查集
class UnionFind {
public:
    UnionFind(int n) {
        for(auto i = 0; i < n; ++i) {
            parent_.emplace_back(i);
            count_ = n;
            size_.emplace_back(1);
        }
    }

    void Connect(int n, int m) {
        int rootN = find(n);
        int rootM = find(m);
        if (rootN == rootM) {
            return;
        }

        if (size_[rootN] < size_[rootM]) {
            parent_[rootN] = rootM;
            size_[rootM] += size_[rootN];
        } else {
            parent_[rootM] = rootN;
            size_[rootN] += size_[rootM];
        }
        count_ -= 1;
    }

    bool IsConnected(int n, int m) {
        int parentN = find(n);
        int parentM = find(m);
        return parentN == parentM;
    }

private:
    int find(int n) {
        while (parent_[n] != n) {
            parent_[n] = parent_[parent_[n]];
            n = parent_[n];
        }
        return n;
    }

private:
    std::vector<int> parent_; // 记录顶点
    std::vector<int> size_; // 权重
    int count_;
};  // class UnionFind

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //normalSolve(board);
        UFSolve(board);
    }

    void UFSolve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int col = board[0].size();
        if (col == 0) {
            return;
        }

        auto pos = [&row, &col](int i, int j)  -> int {
            return i * col + j;
        };

        UnionFind uf(row * col + 1);

        for (auto i = 0; i < row; ++i) {
            if (board[i][0] == 'O') {
                uf.Connect(pos(i,0), pos(row-1,col-1));
            }

            if (board[i][col-1] == 'O') {
                uf.Connect(pos(i,col-1), pos(row-1, col-1));
            }
        }

        for (auto i = 0; i < col; ++i) {
            if (board[0][i] == 'O') {
                uf.Connect(pos(0,i) , pos(row-1, col-1));
            }

            if (board[row-1][i] == 'O') {
                uf.Connect(pos(row-1, i), pos(row-1, col-1));
            }
        }

        std::vector<std::tuple<int,int>> checkItem;
        checkItem.emplace_back(std::make_tuple(1,0));
        checkItem.emplace_back(std::make_tuple(0,1));
        checkItem.emplace_back(std::make_tuple(0,-1));
        checkItem.emplace_back(std::make_tuple(-1,0));
        for (auto i = 1; i < row-1; ++i) {
            for (auto j = 1; j < col-1; ++j) {
                if (board[i][j] == 'O') {
                    for(auto k = 0; k < checkItem.size(); ++k) {
                        if (board[i+std::get<0>(checkItem[k])][j+std::get<1>(checkItem[k])] == 'O') {
                            uf.Connect(pos(i+std::get<0>(checkItem[k]), j+std::get<1>(checkItem[k])), pos(i,j));
                        }
                    }
                }
            }
        }

        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (!uf.IsConnected(pos(row-1, col-1), pos(i,j))) {
                    board[i][j] = 'X';
                }
            }
        }

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

