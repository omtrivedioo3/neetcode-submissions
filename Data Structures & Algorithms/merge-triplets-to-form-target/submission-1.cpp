class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& target) {
        int n = t.size();
        bool a = false, b = false, c = false;
        // cout << a << b << c << endl;

        for (int i = 0; i < n; i++) {
            if (t[i][0] <= target[0] and t[i][1] <= target[1] and t[i][2] <= target[2]) {
                if (t[i][0] == target[0]) a = true;
                if (t[i][1] == target[1]) b = true;
                if (t[i][2] == target[2]) c = true;
            }
            // cout << a << b << c << endl;
        }
        return (a == b and b == c and a == true);
    }
};
