class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        for (auto& pre : prerequisites) {
            indegree[pre[0]]++;             // 'a' depends on 'b'
            adj[pre[1]].push_back(pre[0]);  // Edge goes from 'b' to 'a'
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        int finish = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            finish++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    ans.push_back(nei);
                    q.push(nei);
                }
            }
        }
        if (finish == numCourses) return ans;
        return {};
    }
};
