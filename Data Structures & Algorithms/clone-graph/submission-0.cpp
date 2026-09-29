/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    unordered_map<Node*, Node*> mp;
    Node* fun(Node* node) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];
        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for (Node* nei : node->neighbors) {
            newNode->neighbors.push_back(fun(nei));
        }
        return mp[node];
    }
    Node* cloneGraph(Node* node) {
        fun(node);
        return mp[node];
    }
};
