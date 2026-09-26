class Solution {
   public:
    void fun(int i, int n, vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int sum,
             int target) {
        if (i == n) {
            if (sum == target) ans.push_back(temp);
            return;
        }
        if(sum>target)return;
        fun(i + 1, n, ans, nums, temp, sum, target);
        temp.push_back(nums[i]);
        fun(i, n, ans, nums, temp, sum + nums[i], target);
        temp.pop_back();
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        fun(0, n, ans, nums, temp, 0, target);
        return ans;
    }
};
