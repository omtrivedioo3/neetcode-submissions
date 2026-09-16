class Solution {
   public:
    int trap(vector<int>& h) {
        int n = h.size(), maxi = 0;
        vector<int> suf(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, h[i]);
            suf[i] = maxi;
        }

        int ans = 0;
        int left = 0, right = n - 1, leftMax = h[left], rightMax = h[right];
        while (left < right) {
            if (h[left] <= h[right]) {
                left++;
                leftMax = max(leftMax, h[left]);
                ans += max(0, leftMax - h[left]);
                cout << max(0, leftMax - h[left]) << " ";
            } else {
                right--;
                rightMax = max(rightMax, h[right]);
                ans += max(0, rightMax - h[right]);
                cout << max(0, rightMax - h[right]) << " ";
            }
        }
        return ans;
    }
};
