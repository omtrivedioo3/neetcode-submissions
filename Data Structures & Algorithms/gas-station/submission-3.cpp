class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int n = cost.size();
        int total = 0, start = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i];
            total -= cost[i];
            if (total < 0) {
                start = i + 1;
                total = 0;
            }
        }
        return start;
    }
};
