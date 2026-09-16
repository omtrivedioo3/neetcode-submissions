class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int k = 2; k < n; k++) {
            if (k+1<n and  nums[k] == nums[k + 1] ) continue;
            int i = 0, j = k - 1, target = -1 * (nums[k]);
            while (i < j) {
                if (i > 0 and nums[i] == nums[i - 1]) {
                    i++;
                    continue;
                }
                if (j < k - 1 and nums[j] == nums[j + 1]) {
                    j--;
                    continue;
                }
                int val = nums[i] + nums[j];
                if (val == target) {
                    st.push_back({nums[i], nums[j], nums[k]});
                    i++;
                } else if (val > target) {
                    j--;

                } else {
                    i++;
                }
            }
        }
        // vector<vector<int>> ans(st.begin(), st.end());
        return st;
    }
};
