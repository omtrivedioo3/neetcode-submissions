class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& in, vector<int>& q) {
        int n = in.size();
        sort(begin(in), end(in));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int m = q.size();
        vector<pair<int, int>> query(m);
        for (int i = 0; i < m; i++) {
            query[i] = {q[i], i};
        }
        vector<int> ans(m);
        sort(begin(query), end(query));

        int i = 0;
        for (int j = 0; j < m; j++) {
            while (i < n and in[i][0] <= query[j].first) {
               pq.push({in[i][1] - in[i][0] + 1, in[i][1]});
                i++;
            }
            while (!pq.empty() and pq.top().second < query[j].first) {
                pq.pop();
            }
            if (pq.size())
               ans[query[j].second] = pq.top().first;
            else
                ans[query[j].second] = -1;
        }
        return ans;
    }
};
