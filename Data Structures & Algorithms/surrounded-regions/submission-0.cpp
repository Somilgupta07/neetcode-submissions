class Solution {
   public:
    int m, n;
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;

        if (board[i][j] != 'O') return;

        board[i][j] = '#';
        dfs(board, i + 1, j); // down
        dfs(board, i - 1, j); // up
        dfs(board, i, j + 1); // right
        dfs(board, i, j - 1); // left
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // first and last col
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        // first and last row
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }

        // mark
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
