class Solution {
   public:
    bool check(int row, int col, vector<vector<char>>& board) {
        int n = 9;
        for (int i = 0; i < 9; i++) {
            if (i != row and board[i][col] == board[row][col]) return true;
            if (i != col and board[row][i] == board[row][col]) return true;
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i <= startRow + 2; i++) {
            for (int j = startCol; j <= startCol + 2; j++) {
                if (i != row and j != col and board[i][j] == board[row][col]) return true;
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    if (check(i, j, board)) return false;
                }
            }
        }
        return true;
    }
};
