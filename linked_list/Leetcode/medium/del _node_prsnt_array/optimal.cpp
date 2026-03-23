// Optimal approach: Stores array values in a hash 
// set for O(1) lookups, yielding an O(N + M) time complexity.
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (st.count(curr->val)) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* result = dummy->next;
        return result;
    }
};