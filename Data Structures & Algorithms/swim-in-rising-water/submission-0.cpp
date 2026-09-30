class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto [cost, row, col] = pq.top();
            pq.pop();
            if (dist[row][col] > cost) continue;

            for (int i = 0; i < 4; i++) {
                int nrow = row + x[i];
                int ncol = col + y[i];
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < n and
                    dist[nrow][ncol] > max(dist[row][col], grid[nrow][ncol])) {
                    dist[nrow][ncol] = max(dist[row][col], grid[nrow][ncol]);
                    pq.push({dist[nrow][ncol], nrow, ncol});
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};
