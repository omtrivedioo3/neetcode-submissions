class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        map<pair<int, int>, vector<pair<int, int>>> mp;
        map<pair<int, int>, int> dist;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp[{points[i][0], points[i][1]}].push_back({points[j][0], points[j][1]});
                mp[{points[j][0], points[j][1]}].push_back({points[i][0], points[i][1]});
            }
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, points[0][0], points[0][1]});
        int ans = 0, edges = 0;
        while (!pq.empty() and edges < n) {
            auto [charge, x, y] = pq.top();
            pq.pop();
            if (dist.find({x, y}) != dist.end()) continue;
            ans += charge;
            dist[{x, y}] = 1;
            edges++;
            for (auto it : mp[{x, y}]) {
                if (dist.find(it) == dist.end()) {
                    int charge1 = abs(it.first - x) + abs(it.second - y);
                    pq.push({charge1, it.first, it.second});
                }
            }
        }
        return ans;
    }
};
