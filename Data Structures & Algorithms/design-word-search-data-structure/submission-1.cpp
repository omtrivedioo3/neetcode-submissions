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
class WordDictionary {
   public:
    Trie* root;
    WordDictionary() { root = new Trie(); }

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
    bool findSeach(int i, int n, string& s, Trie* node) {
        if (i == n) return node->isEndofWorld();
        bool ans = false;
        if (s[i] != '.') {
            if (node->siKeyContained(s[i])) {
                ans |= findSeach(i + 1, n, s, node->get(s[i]));
            } else
                return false;
        } else {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (node->siKeyContained(ch)) {
                    ans |= findSeach(i + 1, n, s, node->get(ch));
                }
            }
        }
        return ans;
    }

    bool search(string word) {
        Trie* node = root;

        return findSeach(0, word.length(), word, node);
    }
};
