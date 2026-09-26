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
        int next_idx = i + 1;
        while (next_idx < n && nums[next_idx] == nums[i]) {
            next_idx++; // Keep moving right while elements are duplicates
        }
        // Make ONE recursive call on the next different element (or n if none left)
        fun(next_idx, n, ans, nums, temp);

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
