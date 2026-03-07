//logic:- bubble sort is not right way to use (not optimal with swap logic)
//ps:-Sort List 148
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        bool swapped;

        do {
            swapped = false;
            ListNode* prev = dummy;
            ListNode* curr = dummy->next;

            while (curr && curr->next) {
                if (curr->val > curr->next->val) {
                    ListNode* second = curr->next;
                    ListNode* third = second->next;

                    prev->next = second;
                    second->next = curr;
                    curr->next = third;

                    swapped = true;
                }
                prev = prev->next;
                curr = prev->next;
            }
        } while (swapped);

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};