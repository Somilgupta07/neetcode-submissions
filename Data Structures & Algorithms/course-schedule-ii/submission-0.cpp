class Solution {
   public:
    vector<int> findOrder(int numcourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numcourses);
        vector<int> indegree(numcourses, 0);

        for (auto pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < numcourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);
            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        if (order.size() != numcourses) return {};
        return order;
    }
};
