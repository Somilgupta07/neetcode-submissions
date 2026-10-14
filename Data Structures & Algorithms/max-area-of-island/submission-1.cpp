class Solution {
   public:
    int solve(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || c < 0 || r >= m || c >= n) return 0;
        if (grid[r][c] == 0 || vis[r][c]) return 0;

        vis[r][c] = true;

        int area = 1;
        area += solve(grid, r + 1, c, vis);
        area += solve(grid, r - 1, c, vis);
        area += solve(grid, r, c + 1, vis);
        area += solve(grid, r, c - 1, vis);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int area = solve(grid, i, j, vis);
                    maxi = max(maxi, area);
                }
            }
        }
        return maxi;
    }
};
