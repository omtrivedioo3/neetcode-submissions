class Solution {
   public:
    bool isAlphaNumeric(char ch) {
        return ((ch >= 'A' and ch <= 'Z') or (ch >= 'a' and ch <= 'z') or
                (ch >= '0' and ch <= '9'));
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            while (i <= j and !isAlphaNumeric(s[i])) i++;
            while (i <= j and !(isAlphaNumeric(s[j]))) j--;
            if (i <= j) {
                if (tolower(s[i]) != tolower(s[j])) return false;
                i++, j--;
            }
        }
        cout << i << " " << j;
        return true;
    }
};
