class Solution {
   public:
    bool check(int i, int j, int n, vector<string>& temp) {
        int row = i, col = j;
        while (row--) {
            if (temp[row][j] == 'Q') return false;
        }

        row = i;
        col = j;
        while (row-- and col--) {
            if (temp[row][col] == 'Q') return false;
        }
        row = i;
        col = j;
        while (row >= 0 and col < n) {
            if (temp[row][col] == 'Q') return false;
            col++;
            row--;
        }
        return true;
    }
    void fun(int i, int n, vector<string>& temp, vector<vector<string>>& ans) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (check(i, j, n, temp)) {
                temp[i][j] = 'Q';
                fun(i + 1, n, temp, ans);
                temp[i][j] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        fun(0, n, board, ans);
        return ans;
    }
};
