// Calculate the length of the linked list to find and 
// delete the middle node.
//ps:-2095. Delete the Middle Node of a Linked List
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int midIndex = length / 2;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < midIndex; i++) {
            prev = curr;
            curr = curr->next;
        }

        if (prev != nullptr) {
            prev->next = curr->next;
            delete curr;
        }

        return head;
    }
};