//logic :- prev cannot be NULL as we cant do NULL->next
//ps:- 82. Remove Duplicates from Sorted List II
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != NULL) {
            if (curr->next != NULL && curr->val == curr->next->val) {
                while (curr->next != NULL && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next; 
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};