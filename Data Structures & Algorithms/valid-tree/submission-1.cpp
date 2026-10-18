class Solution {
   public:
    bool hasCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (int neighbor : adj[node]) {
            if (neighbor == parent) {
                continue;
            }
            if (vis[neighbor]) {
                return true;
            }
            if (hasCycle(neighbor, node, adj, vis)) {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);

        if (hasCycle(0, -1, adj, vis)) {
            return false;
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }

        return true;
    }
};
