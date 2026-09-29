class Solution {
   public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int l = 0, r = last[s[0] - 'a'];
        int i = 0;
        while (i < n) {
            r = max(r, last[s[i] - 'a']);
            if (r == i) {
                ans.push_back(r - l + 1);
                l = r + 1;
            }
            i++;
        }
        return ans;
    }
};
