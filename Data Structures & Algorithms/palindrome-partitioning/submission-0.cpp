class Solution {
   public:
    bool isPeli(string& s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    void fun(int i, int n, string& s, vector<string>& temp, vector<vector<string>>& ans) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        string st;
        for (int j = i; j < n; j++) {
            st += s[j];
            if (isPeli(st)) {
                temp.push_back(st);
                fun(j + 1, n, s, temp, ans);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> temp;
        vector<vector<string>>ans;
        fun(0, n, s, temp, ans);
        return ans;
    }
};
