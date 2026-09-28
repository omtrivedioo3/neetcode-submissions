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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto& x, auto& y) { return x.start < y.start; });
        int ans = 0, cnt = 1;
        vector<int> vec(1e6 + 1, 0);
        for (int i = 0; i < intervals.size(); ++i) {
            vec[intervals[i].start]++;
            vec[intervals[i].end]--;
        }
        for (int i = 1; i <= 1e6; i++) {
            vec[i] += vec[i - 1];
            ans = max(ans, vec[i]);
        }
        return ans;
    }
};
