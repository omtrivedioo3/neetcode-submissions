class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mini = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};
