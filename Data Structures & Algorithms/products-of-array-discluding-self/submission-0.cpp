class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prf(n + 2, 1), suf(n + 2, 1);
        for (int i = 0; i < n; i++) {
            prf[i + 1] = prf[i] * nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i + 1] = suf[i + 2] * nums[i];
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            ans.push_back(prf[i - 1] * suf[i + 1]);
        }
        return ans;
    }
};
