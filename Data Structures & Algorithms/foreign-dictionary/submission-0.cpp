class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, -1);
        int n = words.size(), word = 0;
        set<char> unique;
        for (int i = 0; i < n; i++) {
            for (auto it : words[i]) {
                indegree[it - 'a'] = 0;
                unique.insert(it);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            string first = words[i], second = words[i + 1];
            int j = 0, k = 0;
            while (j < first.length() and k < second.length() and first[j] == second[k]) {
                k++, j++;
            }
            if (j < first.length() and k < second.length()) {
                adj[first[j] - 'a'].push_back(second[k] - 'a');
                indegree[second[k] - 'a']++;
            } else if (j < first.length() && k == second.length()) {
                // If we exhausted the second word but the first word still has characters,
                // it means the second word is a prefix of the first, which is invalid.
                return "";
            }
        }

        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0) {
                // cout << i << endl;
                q.push(i);
            }
        }
        string ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            // cout << node << " ";
            ans.push_back((char)node + 'a');

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        // cout << ans << " " << word;
        if (ans.length() == unique.size()) return ans;
        return "";
    }
};
