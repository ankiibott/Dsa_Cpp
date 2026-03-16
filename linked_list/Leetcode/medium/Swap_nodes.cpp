// Logic: Always for swapping nodes, a pointer to one node before is needed.
//ps:-24. Swap Nodes in Pairs
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;

            prev = curr;
            curr = curr->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};