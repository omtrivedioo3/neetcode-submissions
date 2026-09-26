class Solution {
   public:
    void fun(int i, int n, vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        fun(i + 1, n, ans, nums, temp);
        temp.pop_back();
        for (int j = i; j <= n; j++) {
            if (j == n or nums[j] != nums[i]) {
                fun(j, n, ans, nums, temp);
                break;
            }
        }
        // fun(n, n, ans, nums, temp);

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        fun(0, n, ans, nums, temp);
        return ans;
    }
};
