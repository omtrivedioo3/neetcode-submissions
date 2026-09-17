/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    map<Node*, Node*> mp;
    Node* fun(Node* head) {
        if(!head)return nullptr;
        if (mp.find(head) != mp.end()) return mp[head];

        Node* node = new Node(head->val);
        mp[head] = node;
        if (head->next) {
            // if (mp.find(head->next) != mp.end())
            //     return mp[head->next];
            // else
                mp[head]->next = fun(head->next);
        }
        if (head->random) {
            // if (mp.find(head->random) != mp.end())
            //     return mp[head->random];
            // else
                mp[head]->random = fun(head->random);
        }
        return mp[head];
    }
    Node* copyRandomList(Node* head) { return fun(head); }
};
