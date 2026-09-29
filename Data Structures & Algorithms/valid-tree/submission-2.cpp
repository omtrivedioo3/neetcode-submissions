class Solution {
   public:
    bool dfs(int node, int parent, int n, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                if (dfs(it, node, n, adj, vis)) return true;
            } else
                return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);

        for (auto& pre : p) {
            adj[pre[0]].push_back(pre[1]);
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, n, adj, vis)) return false;
                cnt++;
            }
        }

        return cnt == 1;
    }
};
