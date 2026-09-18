class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + ((r - l) / 2);
            if (nums[mid] == target) return mid;
            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] and target <= nums[mid]) {
                    r = mid;
                } else
                    l = mid + 1;
            } else {
                if (target >= nums[mid] and target <= nums[r]) {
                    l = mid;
                } else
                    r = mid - 1;
            }
        }
        return -1;
    }
};
