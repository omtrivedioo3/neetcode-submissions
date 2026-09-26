class Solution {
   public:
    void fun(int i, int n, int open, int close, string& temp, vector<string>& ans) {
        if (i == n) {
            if (open == n / 2 and close == n / 2) {
                ans.push_back(temp);
            }
            return;
        }
        if (open > n / 2 or close > open) return;
        if (open < n / 2) {
            temp.push_back('(');
            fun(i + 1, n, open + 1, close, temp, ans);
            temp.pop_back();
        }
        if (close < n / 2 and close < open) {
            temp.push_back(')');
            fun(i + 1, n, open, close + 1, temp, ans);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        fun(0, 2 * n, 0, 0, temp, ans);
        return ans;
    }
};
