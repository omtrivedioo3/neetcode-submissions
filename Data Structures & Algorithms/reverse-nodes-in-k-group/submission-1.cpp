class Solution {
public:
    int getLen(ListNode* head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int n = getLen(head);
        
        // Dummy node helps handle the head of the list easily
        ListNode dummy(-1);
        dummy.next = head;
        
        // groupPrev tracks the node immediately BEFORE the current k-group
        ListNode* groupPrev = &dummy;
        ListNode* temp = head;

        for (int i = 0; i < n / k; i++) {
            ListNode* prev = nullptr;
            ListNode* groupStart = temp; // This node will become the tail of this group

            // Reverse exactly k nodes independently
            for (int j = 0; j < k; j++) {
                ListNode* next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }

            // 1. Connect the tail of our newly reversed group to the upcoming unreversed nodes
            groupStart->next = temp;
            
            // 2. Connect the previous group to the head of our newly reversed group
            groupPrev->next = prev;
            
            // 3. Move groupPrev forward to the tail of this group for the next iteration
            groupPrev = groupStart;
        }

        return dummy.next;
    }
};