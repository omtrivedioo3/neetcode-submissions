class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) return findMedianSortedArrays(nums2, nums1);

        int center = (n + m + 1) / 2;

        int total = n + m;

        int left = 0, right = n;
        while (left <= right) {
            int mid1 = (left + right) / 2;
            int mid2 = center - mid1;

            int l1 = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN;
            int l2 = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN;
            int r1 = mid1 < n ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < m ? nums2[mid2] : INT_MAX;

            if (l1 <= r2 and l2 <= r1) {
                if (total % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                right = mid1 - 1;
            } else
                left = mid1 + 1;
        }
        return -1;
    }
};
