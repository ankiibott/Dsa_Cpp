//ps:-2487. Remove Nodes From Linked List

// Logic: Uses a monotonic decreasing
//  stack to remove all nodes that have a greater value to their right.
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* curr = head;

        while (curr != nullptr) {
            while (!nodes.empty() && nodes.back()->val < curr->val) {
                nodes.pop_back();
            }
            nodes.push_back(curr);
            curr = curr->next;
        }
        //re-link
        ListNode* dummy = new ListNode(0);
        curr = dummy;
        for (ListNode* node : nodes) {
            curr->next = node;
            curr = curr->next;
        }
        curr->next = nullptr;

        return dummy->next;
    }
};