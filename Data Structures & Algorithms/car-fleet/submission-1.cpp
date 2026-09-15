class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        priority_queue<double> pq;
        for (int i = 0; i < n; i++) {
            double t = (double)(target - v[i].first) / v[i].second;
            cout << t << " ";
            if (!pq.empty() and pq.top() >= t) continue;
            pq.push(t);
        }
        return pq.size();
    }
};
