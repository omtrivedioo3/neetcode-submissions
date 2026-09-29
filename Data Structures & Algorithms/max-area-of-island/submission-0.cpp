class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;
        int ans = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    ans = max(ans, bfs(grid, r, c));
                    islands++;
                }
            }
        }

        return ans;
    }
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        grid[r][c] = 0;
        q.push({r, c});
        int cnt = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            cnt++;
            int row = node.first, col = node.second;
            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() &&
                    grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }
        return cnt;
    }
};
