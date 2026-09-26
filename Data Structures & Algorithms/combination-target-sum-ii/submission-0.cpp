class Solution {
   public:
    void fun(int i, int n, vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int sum,
             int target) {
        if (i == n) {
            if (sum == target) ans.push_back(temp);
            return;
        }
        if (sum > target) return;
        temp.push_back(nums[i]);
        fun(i + 1, n, ans, nums, temp, sum + nums[i], target);
        temp.pop_back();
        for (int j = i; j <= n; j++) {
            if (j==n or nums[j] != nums[i]) {
                fun(j, n, ans, nums, temp, sum, target);
                break;
            }
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        fun(0, n, ans, nums, temp, 0, target);
        return ans;
    }
};
