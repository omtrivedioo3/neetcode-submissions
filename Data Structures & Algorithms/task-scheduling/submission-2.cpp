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
            if (pq.size() > n) {
                int cnt = n + 1;
                vector<int> temp;
                while (cnt--) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
                ans += (n + 1);
                for (auto it : temp) {
                    if (it - 1 > 0) {
                        pq.push(it - 1);
                    }
                }
               
            } else {
                int cnt = pq.size();
                vector<int> temp;
                while (!pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
                ans += (n + 1);
                for (auto it : temp) {
                    if (it - 1 > 0) {
                        pq.push(it - 1);
                    }
                }
                if (pq.empty()) {
                    ans -= (n + 1 - cnt);
                    break;
                }
            }
        }
        return ans;
    }
};
