class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n = hand.size();
        if (n % g != 0) return false;

        vector<int> vis(1001, 0);
        for (auto it : hand) vis[it]++;
        for (int i = 0; i < 1001; i++) {
            while (vis[i]) {
                int size = g, start = i;
                while (size--) {
                    if (vis[start] == 0) return false;
                    vis[start]--;
                    start++;
                }
            }
        }
        return true;
    }
};
