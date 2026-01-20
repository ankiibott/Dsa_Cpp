//logic :- get the length/k even or odd then s>0?1 else 0 for current_size
//ps:-725:-Split Linked List in Parts
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

        int s = length / k;
        int extra = length % k;

        vector<ListNode*> result;
        temp = head;

        for (int i = 0; i < k; i++) {
            result.push_back(temp);

            int current_size = s + (extra > 0 ? 1 : 0);
            extra--;

            for (int j = 0; j < current_size - 1; j++) {
                if (temp != NULL) {
                    temp = temp->next;
                }
            }

            if (temp != NULL) {
                ListNode* nextPartHead = temp->next;
                temp->next = NULL;
                temp = nextPartHead;
            }
        }

        return result;
    }
};