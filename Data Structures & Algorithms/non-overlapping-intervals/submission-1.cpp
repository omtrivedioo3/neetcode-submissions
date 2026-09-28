class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int n = in.size();
        int ans = 1, back = in[0][1];
        for (int i = 1; i < n; i++) {
            if (back <= in[i][0]) {
                back = max(back, in[i][1]);
                ans++;
            }
        }
        return n - ans;
    }
};
