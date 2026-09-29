class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> p(n, vector<int>(m, 0));
        vector<vector<int>> a(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            p[i][0] = 1;
            q.push({i, 0});
        }
        for (int i = 0; i < m; i++) {
            p[0][i] = 1;
            q.push({0, i});
        }
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto it = q.front();
            int row = it.first;
            int col = it.second;
            q.pop();
            p[row][col] = 1;
            for (int i = 0; i < 4; i++) {
                int nrow = row + x[i];
                int ncol = col + y[i];
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and
                    h[nrow][ncol] >= h[row][col] and p[nrow][ncol] == 0) {
                    p[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            a[i][m - 1] = 1;
            q.push({i, m - 1});
        }
        for (int i = 0; i < m; i++) {
            a[n - 1][i] = 1;
            q.push({n - 1, i});
        }
        while (!q.empty()) {
            auto it = q.front();
            int row = it.first;
            int col = it.second;
            q.pop();
            a[row][col] = 1;
            for (int i = 0; i < 4; i++) {
                int nrow = row + x[i];
                int ncol = col + y[i];
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and
                    h[nrow][ncol] >= h[row][col] and a[nrow][ncol] == 0) {
                    a[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] and p[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
