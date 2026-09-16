class Solution {
   public:
    int trap(vector<int>& h) {
        int n = h.size(), maxi = 0;
        vector<int> suf(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, h[i]);
            suf[i] = maxi;
        }

        int ans = 0;
        maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, h[i]);
            if (min(maxi, suf[i]) > h[i]) {
                ans += abs(h[i] - min(maxi, suf[i]));
            }
        }
        return ans;
    }
};
