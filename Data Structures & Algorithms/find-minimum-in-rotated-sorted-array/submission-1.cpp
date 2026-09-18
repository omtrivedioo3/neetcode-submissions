class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        if (nums[i] < nums[j] or n==1) return nums[0];
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[i] < nums[mid]) {
                i = mid;
            } else
                j = mid;
        }
        return nums[j+1];
    }
};
