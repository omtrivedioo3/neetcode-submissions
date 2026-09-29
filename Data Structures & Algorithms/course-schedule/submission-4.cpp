class Solution {
   public:
    bool dfs(int node, int parent, int n, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& path) {
        vis[node] = 1;
        path[node] = 1;
        for (auto it : adj[node]) {
            if (path[it])
                return true;
            else if (!vis[it]) {
                if (dfs(it, node, n, adj, vis, path)) return true;
            }
        }
        path[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);

        for (auto& pre : p) {
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, n, adj, vis, path)) return false;
            }
        }

        return true;
    }
};