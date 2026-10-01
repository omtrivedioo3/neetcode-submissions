class Solution {
   public:
    string fun(int i, int j, string s) {
        while (i >= 0 and j < s.length()) {
            if (s[i] != s[j]) break;
            i--, j++;
        }

        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int ans = 0;
        string st;
        for (int i = 0; i < n; i++) {
            string s1 = fun(i, i, s);
            if (s1.length() > ans) {
                ans = s1.length();
                st = s1;
            }
            if (i < n - 1) {
                s1 = fun(i, i + 1, s);
                if (s1.length() > ans) {
                    ans = s1.length();
                    st = s1;
                }
            }
        }
        return st;
    }
};
