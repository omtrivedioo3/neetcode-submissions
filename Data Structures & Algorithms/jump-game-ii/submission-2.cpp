#include <cstring>
class Solution {
   public:
    int memo[1001];
    int fun(int i, int n, vector<int>& nums) {
        if (i >= n - 1) return 0;
        if (memo[i] != -1) return memo[i];
        int ans = 1e9;
        for (int jump = 1; jump <= nums[i]; jump++) {
            ans = min(ans, 1 + fun(i + jump, n, nums));
        }
        return memo[i] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size(), jump = 0, l = 0, r = 0;

        while (r < n-1) {
            int further = 0;
            for (int i = l; i <= r; i++) {
                further = max(further, i + nums[i]);
            }
            l = r + 1;
            r = further;
            jump++;
        }
        return jump;
    }
};
