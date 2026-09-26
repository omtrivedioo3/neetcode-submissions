class Solution {
   public:
    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0, 1, 0, -1};
    bool fun(int i, int j, int k, int n, int m, int z, vector<vector<char>>& board, string word,
             vector<vector<int>>& vis) {
        if (k == z) return true;
        if (i >= n or i < 0 or j >= m or j < 0 or vis[i][j] or board[i][j] != word[k]) return false;
        vis[i][j] = 1;
        bool ans = false;
        for (int l = 0; l < 4; l++) {
            int ni = i + row[l];
            int nj = j + col[l];
            ans |= fun(ni, nj, k + 1, n, m, z, board, word, vis);
        }
        vis[i][j] = 0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size(), z = word.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
                    if (fun(i, j, 0, n, m, z, board, word, vis)) return true;
                }
            }
        }
        return false;
    }
};
