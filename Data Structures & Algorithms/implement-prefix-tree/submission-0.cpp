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
class PrefixTree {
   public:
    Trie* root;
    PrefixTree() { root = new Trie(); }

    void insert(string word) {
        Trie* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->siKeyContained(word[i])) {
                node->put(word[i], new Trie());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Trie* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->siKeyContained(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEndofWorld();
    }

    bool startsWith(string word) {
        Trie* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->siKeyContained(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};
