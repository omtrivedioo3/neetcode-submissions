class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!st.count(nums[i] - 1)) {
                int val = nums[i];
                int cnt = 0;
                while (st.count(val)) {
                    cnt++;
                    val++;
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
