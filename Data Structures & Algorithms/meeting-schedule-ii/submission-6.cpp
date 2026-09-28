/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& in) {
        if (in.size() == 0) return 0;
        sort(in.begin(), in.end(), [](auto& x, auto& y) { return x.start < y.start; });
        int ans = 1;
        priority_queue<int, vector<int>, greater<>> pq;
        pq.push(in[0].end);
        for (int i = 1; i < in.size(); ++i) {
            if (in[i].start >= pq.top()) {
                pq.pop();
            }
            // Always push the new meeting's end time
            pq.push(in[i].end);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
