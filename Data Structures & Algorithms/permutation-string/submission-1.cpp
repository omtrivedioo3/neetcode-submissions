class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n>m)return false;
        vector<int> vis(26, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            vis[s1[i] - 'a']++;
            if (vis[s1[i] - 'a'] == 1) cnt++;
        }
        for (int i = 0; i < n; i++) {
            vis[s2[i] - 'a']--;
            if (vis[s2[i] - 'a'] == 0) cnt--;
        }
        if (cnt == 0) return true;
        for (int i = n; i < m; i++) {
            vis[s2[i - n] - 'a']++;
            if (vis[s2[i - n] - 'a'] == 1) cnt++;
            vis[s2[i] - 'a']--;
            if (vis[s2[i] - 'a'] == 0) cnt--;
            if (cnt == 0) return true;
        }
        return false;
    }
};
