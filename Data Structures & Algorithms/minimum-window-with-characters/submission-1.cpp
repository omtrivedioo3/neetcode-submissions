class Solution {
   public:
    string minWindow(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if (n > m) return "";
        unordered_map<char, int> vis;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            vis[s2[i]]--;
            if (vis[s2[i]] == -1) cnt++;
        }
        cout<<cnt<<" ";
        int i = 0, j = 0, ind = -1, mini = m + 1;
        while (j < m) {
            vis[s1[j]]++;
            if (vis[s1[j]] == 0) cnt--;
            // cout << cnt << " ";
            while (cnt == 0 and i <= j) {
                if ((j - i + 1) < mini) {
                    mini = j - i + 1;
                    ind = i;
                }
                vis[s1[i]]--;
                if (vis[s1[i]] == -1) cnt++;
                i++;
            }
            j++;
        }
        if (ind == -1) return "";
        cout<<mini;
        return s1.substr(ind, mini);
    }
};
