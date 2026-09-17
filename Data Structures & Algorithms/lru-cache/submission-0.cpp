class LinkNode {
   public:
    int val;
    int key;
    LinkNode* prev;
    LinkNode* next;

    LinkNode(int key, int val) {
        this->val = val;
        this->key = key;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
   public:
    int limit = 0, len = 0;
    LinkNode* head = new LinkNode(-1, -1);
    LinkNode* last = new LinkNode(-1, -1);
    unordered_map<int, LinkNode*> mp;
    LRUCache(int capacity) {
        limit = capacity;
        head->next = last;
        last->prev = head;
    }

    void addNode(LinkNode* node) {
        LinkNode* nextNode = head->next;
        head->next = node;
        node->prev = head;
        nextNode->prev = node;
        node->next = nextNode;
    }
    void removeNode(LinkNode* node) {
        LinkNode* prev = node->prev;
        LinkNode* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void update(LinkNode* node) {
        removeNode(node);
        addNode(node);
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        LinkNode* node = mp[key];
        int val = node->val;
        removeNode(node);
        addNode(node);
        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            LinkNode* node = mp[key];
            node->val = value;
            update(node);
        } else {
            LinkNode* node = new LinkNode(key, value);
            if (len == limit) {
                LinkNode* lru = last->prev;

                mp.erase(lru->key);

                removeNode(lru);
                delete lru;

                mp[key] = node;
                addNode(node);
            } else {
                len++;
                mp[key] = node;
                addNode(node);
            }
        }
    }
};
