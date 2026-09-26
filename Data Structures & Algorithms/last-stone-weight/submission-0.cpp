class Solution {
   public:
    int lastStoneWeight(vector<int>& st) {
        priority_queue<int> pq;
        int n = st.size();
        int first = st[0];
        for (int i = 0; i < n; i++) {
            pq.push(st[i]);
        }
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            pq.push(abs(first - second));
        }
        return pq.top();
    }
};
