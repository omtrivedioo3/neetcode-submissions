#include <cstring>
class Solution {
   public:
    int memo[1001];
    bool fun(int i, int n, vector<int>& nums) {
        if (i == n - 1) return true;
        if (i >= n) return false;
        if (memo[i] != -1) return memo[i];
        bool ans = false;
        for (int jump = 1; jump <= nums[i]; jump++) {
            ans |= fun(i + jump, n, nums);
        }
        return memo[i] = ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(memo, -1, sizeof(memo));
        return fun(0, n, nums);
    }
};
