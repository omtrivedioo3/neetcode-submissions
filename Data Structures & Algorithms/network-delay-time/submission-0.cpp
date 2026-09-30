class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            int u = it[0], v = it[1], t = it[2];
            adj[u].push_back({v, t});
        }
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        int ans = 0;
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (dist[node] < time) continue;
            ans = max(ans, dist[node]);
            for (auto it : adj[node]) {
                int child = it.first, cost = it.second;
                if (dist[child] > time + cost) {
                    dist[child] = time + cost;
                    pq.push({dist[child], child});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
        }
        return ans;
    }
};
