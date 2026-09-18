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
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(-1);
        ListNode* listAns = temp;
        while (l1 and l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }
        if (l1)
            temp->next = l1;
        else if (l2)
            temp->next = l2;
        return listAns->next;
    }
    ListNode* merge(int i, int j, vector<ListNode*>& lists) {
        if (i > j) return nullptr;
        if (i == j) return lists[i];
        int mid = (i + j) / 2;

        ListNode* left = merge(i, mid, lists);
        ListNode* right = merge(mid + 1, j, lists);
        return mergeList(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;

        return merge(0, n - 1, lists);
    }
};
