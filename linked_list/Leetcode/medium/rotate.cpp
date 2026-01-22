//ps:-61. Rotate List

/*logic = two pointer tail and prev tail at last and prev at previous posn of tail 
just conect tail->next = head and then change head then make prev_.next =NULL */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        k = k % len;
        if (k == 0) return head;

        for (int i = 0; i < k; i++) {
            ListNode* tail = head;
            ListNode* prev = NULL;
            while (tail->next) {
                prev = tail;
                tail = tail->next;
            }
            tail->next = head;
            head = tail;
            prev->next = NULL;
        }
        return head;
    }
};