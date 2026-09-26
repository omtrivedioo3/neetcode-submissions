class Solution {
   public:
    void fun(int i, int n, vector<int>& nums, vector<vector<int>>& ans) {
        if (i == n) {
            ans.push_back(nums);
            return;
        }
        // fun(i + 1, n, nums, ans);

        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            fun(i + 1, n, nums, ans);
            swap(nums[i], nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        fun(0, n, nums, ans);
        return ans;
    }
};
