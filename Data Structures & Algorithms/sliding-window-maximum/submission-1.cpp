class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k - 1; i++) {
            pq.push({nums[i], i});
        }

        vector<int> ans;
        for (int i = k - 1; i < n; i++) {
            pq.push({nums[i], i});
            while (i - pq.top().second >= k) pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
