class Solution {
   public:
    void fun(int i, int n, vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        fun(i + 1, n, ans, nums, temp);
        temp.push_back(nums[i]);
        fun(i + 1, n, ans, nums, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n= nums.size();
        fun(0, n, ans, nums, temp);
        return ans;
    }
};
