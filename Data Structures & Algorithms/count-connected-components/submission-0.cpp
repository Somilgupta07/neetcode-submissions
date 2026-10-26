class Solution {
   public:
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis) {
        vis[node] = true;
        for (auto nei : adj[node]) {
            if (!vis[nei]) {
                dfs(adj, nei, vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(adj, i, vis);
            }
        }
        return cnt;
    }
};
