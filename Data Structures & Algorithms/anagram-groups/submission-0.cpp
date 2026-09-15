class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<vector<int>, vector<string>> mp;
        for (auto st : strs) {
            vector<int> temp(26, 0);
            for (auto it : st) {
                temp[it - 'a']++;
            }
            mp[temp].push_back(st);
        }
        vector<vector<string>> ans;
        for (auto it : mp) ans.push_back(it.second);
        return ans;
    }
};
