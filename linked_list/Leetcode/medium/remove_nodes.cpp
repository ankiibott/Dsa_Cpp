//ps:-2487. Remove Nodes From Linked List

// Logic: Uses a monotonic decreasing
//  stack to remove all nodes that have a greater value to their right.
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> stack;
        ListNode* curr = head;

        while (curr != nullptr) {
            while (!stack.empty() && stack.back()->val < curr->val) {
                stack.pop_back();
            }
            stack.push_back(curr);
            curr = curr->next;
        }

        ListNode* dummy = new ListNode(0);
        curr = dummy;
        for (ListNode* node : stack) {
            curr->next = node;
            curr = curr->next;
        }
        curr->next = nullptr;

        return dummy->next;
    }
};