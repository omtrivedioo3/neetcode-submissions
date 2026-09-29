class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            sum = max(0, sum);
        }
        return maxi;
    }
};
