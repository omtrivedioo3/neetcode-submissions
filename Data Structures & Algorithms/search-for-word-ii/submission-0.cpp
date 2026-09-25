class Trie {
   public:
    Trie* node[26];
    bool isEnd = false;
    Trie* get(char ch) { return node[ch - 'a']; }
    void put(char ch, Trie* nd) { node[ch - 'a'] = nd; }
    bool siKeyContained(char ch) { return node[ch - 'a'] != nullptr; }

    void setEnd() { isEnd = true; }
    bool isEndofWorld() { return isEnd; }
};
class Solution {
   public:
    Trie* root = new Trie();
    void addWord(string word) {
        Trie* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->siKeyContained(word[i])) {
                node->put(word[i], new Trie());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    set<string> st;
    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0, 1, 0, -1};
    void fun(int i, int j, int n, int m, string& s, vector<vector<char>>& board,
             vector<vector<int>>& vis, Trie* node) {
        if (i >= n or i < 0 or j >= m or j < 0 or vis[i][j] == 1 or
            !node->siKeyContained(board[i][j]))
            return;

        Trie* nextNode = node->get(board[i][j]);
        s.push_back(board[i][j]);
        vis[i][j] = 1;
        if (nextNode->isEndofWorld()) {
            // cout << s << endl;
            st.insert(s);
            // return;
        }
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ni = row[k] + i;
            int nj = col[k] + j;
            fun(ni, nj, n, m, s, board, vis, nextNode);
        }
        vis[i][j] = 0;
        s.pop_back();
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        int len = words.size();

        for (int i = 0; i < len; i++) {
            addWord(words[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (root->siKeyContained(board[i][j])) {
                    Trie* node = root;
                    // cout << i << " " << j << endl;
                    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
                    string s;
                    fun(i, j, n, m, s, board, vis, node);
                }
            }
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};
