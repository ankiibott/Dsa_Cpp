// Removes nodes from a linked list by checking each
//  node's value against all elements in the given array 
// (O(N*M) time complexity).
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            bool shouldRemove = false;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == curr->val) {
                    shouldRemove = true;
                    break;
                }
            }

            if (shouldRemove) {
                ListNode* temp = curr;
                if (curr == head) {
                    curr = curr->next;
                    prev->next = curr;
                    head = curr;
                } else {
                    prev->next = curr->next;
                    curr = curr->next;
                }
                delete temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};