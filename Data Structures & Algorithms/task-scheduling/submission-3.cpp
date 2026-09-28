class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int frq[26] = {0};
        for (auto it : tasks) {
            frq[it - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (frq[i]) pq.push(frq[i]);
        }
        int ans = 0;
        while (!pq.empty()) {
            int time = 0;
            vector<int> temp;

            // Try to pull up to n+1 tasks
            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                    time++;
                }
            }

            // Push remaining tasks back into the queue
            for (auto t : temp) {
                if (t > 0) pq.push(t);
            }

            // If the queue is empty, we only add the actual time taken.
            // Otherwise, we add the full n+1 cycle (including idles).
            ans += pq.empty() ? time : n + 1;
        }
        return ans;
    }
};
