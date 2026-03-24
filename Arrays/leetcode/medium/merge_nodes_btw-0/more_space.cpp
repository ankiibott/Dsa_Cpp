// Iterates through the linked list, summing values between 
// consecutive 0s, and creates a new list with these summed values 
// using extra space
// ps:-2181. Merge Nodes in Between Zeros
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        ListNode* start = head;
        while (start != nullptr && start->next != nullptr) {
            ListNode* end = start->next;
            int sum = 0;
            
            while (end != nullptr && end->val != 0) {
                sum += end->val;
                end = end->next;
            }
            
            if (sum > 0) {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            
            start = end;
        }
        
        return dummy->next;
    }
};
