class Solution {
   public:
    int cnt = 0;
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // check upper col
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // check upper left col
        int i = row - 1;
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        // check upper right col
         i = row - 1;
         j = col + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void solve(vector<string>& board, int row, int n) {
        if (row == n) {
            cnt++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return cnt;
    }
};