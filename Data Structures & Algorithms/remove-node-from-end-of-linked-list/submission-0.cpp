/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    int findLength(ListNode* node) {
        int cnt = 0;
        while (node) {
            cnt++;
            node = node->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = findLength(head);
        int pos = len - n;
        cout << pos;
        if (pos == 0) return head->next;
        ListNode* temp = head;
        pos--;
        while (pos--) {
            temp = temp->next;
        }
        if (temp->next->next)
            temp->next = temp->next->next;
        else
            temp->next = nullptr;
        return head;
    }
};
