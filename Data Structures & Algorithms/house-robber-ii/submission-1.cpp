class Solution {
   public:
    vector<int> memo, memo2;

    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        memo2.resize(nums.size(), -1);
        int n = nums.size();
        if(n==1)return nums[0];
        return max(dfs(nums, 0, n - 1, memo), dfs(nums, 1, n, memo2));
    }

    int dfs(vector<int>& nums, int i, int n, vector<int>& memo) {
        if (i >= n) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        memo[i] = max(dfs(nums, i + 1, n, memo), nums[i] + dfs(nums, i + 2, n, memo));
        return memo[i];
    }
};
