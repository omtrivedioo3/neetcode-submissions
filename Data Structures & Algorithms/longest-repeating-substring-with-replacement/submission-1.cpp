class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;
        int i = 0, j = 0, ans = 0, maxi = 0;
        while (j < n) {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            while (j - i + 1 - maxi > k) {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
