class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> value;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                int num = nums[i] + 1, cnt = 1;
                while (mp.find(num) != mp.end()) {
                    if (value.find(num) != value.end()) {
                        cnt += value[num];
                        break;
                    }
                    for (auto ind : mp[num]) {
                        vis[ind] = 1;
                    }
                    cnt++;
                    num++;
                }
                value[nums[i]] = cnt;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
