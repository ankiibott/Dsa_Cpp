// Doubles the linked list value in a single pass 
// using a look-ahead carry technique (adds 1 if the next node's value is >= 5).
//ps:-2816. Double a Number Represented as a Linked List
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head->val >= 5) {
            head = new ListNode(0, head);
        }

        ListNode* curr = head;
        while (curr != nullptr) {
            curr->val = (curr->val * 2) % 10;

            if (curr->next != nullptr && curr->next->val >= 5) {
                curr->val += 1;
            }
            
            curr = curr->next;
        }
        return head;
    }
};