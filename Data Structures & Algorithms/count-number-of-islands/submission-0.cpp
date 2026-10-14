class Solution {
   public:
    void solve(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> que;
        que.push({row, col});
        vis[row][col] = true;

        while (!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();

            // Down
            if (r + 1 < m && grid[r + 1][c] == '1' && !vis[r + 1][c]) {
                vis[r + 1][c] = true;
                que.push({r + 1, c});
            }

            // Up
            if (r - 1 >= 0 && grid[r - 1][c] == '1' && !vis[r - 1][c]) {
                vis[r - 1][c] = true;
                que.push({r - 1, c});
            }

            // Right
            if (c + 1 < n && grid[r][c + 1] == '1' && !vis[r][c + 1]) {
                vis[r][c + 1] = true;
                que.push({r, c + 1});
            }

            // Left
            if (c - 1 >= 0 && grid[r][c - 1] == '1' && !vis[r][c - 1]) {
                vis[r][c - 1] = true;
                que.push({r, c - 1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    solve(grid, i, j, vis);
                }
            }
        }
        return ans;
    }
};
