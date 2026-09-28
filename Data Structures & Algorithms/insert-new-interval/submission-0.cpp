class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int st = newInterval[0];
        int nd = newInterval[1];
        int i = 0, n = in.size();
        while (i < n and in[i][1] < st) {
            ans.push_back(in[i]);
            i++;
        }
        while (i < n and nd >= in[i][0]) {
            st = min(st, in[i][0]);
            nd = max(nd, in[i][1]);
            i++;
        }
        vector<int> vec;
        vec.push_back(st);
        vec.push_back(nd);
        ans.push_back(vec);

        while (i < n) {
            ans.push_back(in[i]);
            i++;
        }
        return ans;
    }
};
