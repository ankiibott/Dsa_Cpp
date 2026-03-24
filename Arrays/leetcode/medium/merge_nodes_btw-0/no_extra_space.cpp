// Iterates through the list summing nodes between 0s, and 
// updates the existing nodes in-place without using extra space.
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next;
        ListNode* nextSum = head->next;
        
        while (nextSum != nullptr) {
            int sum = 0;
            while (nextSum->val != 0) {
                sum += nextSum->val;
                nextSum = nextSum->next;
            }
            
            modify->val = sum;
            nextSum = nextSum->next;
            modify->next = nextSum;
            modify = modify->next;
        }
        
        return head->next;
    }
};