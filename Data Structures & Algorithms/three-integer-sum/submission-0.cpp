class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int k = 2; k < n; k++) {
            int i = 0, j = k - 1, target = -1 * (nums[k]);
            while (i < j) {
                int val = nums[i] + nums[j];
                if (val == target) {
                    st.insert({nums[i], nums[j], nums[k]});
                    i++;
                } else if (val > target) {
                    j--;
                } else
                    i++;
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
