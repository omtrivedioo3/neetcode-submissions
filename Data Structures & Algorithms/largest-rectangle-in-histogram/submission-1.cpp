class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prf(n, -1), suf(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prf[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                suf[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = (suf[i] - prf[i]) - 1;
            // cout << suf[i] << " " << prf[i] << endl;
            ans = max(width * heights[i], ans);
        }
        return ans;
    }
};
