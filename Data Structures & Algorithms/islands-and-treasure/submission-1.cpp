class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<tuple<int, int, int>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) pq.push({0, i, j});
            }
        }
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto [time, row, col] = pq.front();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + x[i];
                int ncol = col + y[i];
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and
                    grid[nrow][ncol] == INT_MAX) {
                    grid[nrow][ncol] = 1 + time;
                    pq.push({time + 1, nrow, ncol});
                }
            }
        }
        return;
    }
};
