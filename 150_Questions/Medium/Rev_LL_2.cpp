//logic:- detach then attach once reverse from (left,right) 

//ps:-92. Reverse Linked List II


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* leftPre = dummy;
        
        for (int i = 1; i < left; i++) {
            leftPre = leftPre->next;
        }
        
        ListNode* rightNode = leftPre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }
        
        ListNode* leftNode = leftPre->next;
        ListNode* rightNext = rightNode->next;
        rightNode->next = NULL; 
        
        ListNode* curr = leftNode;
        ListNode* newHead = NULL;
        
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = newHead;
            newHead = curr;
            curr = nextTemp;
        }

        leftPre->next = newHead;
        leftNode->next = rightNext;

        return dummy->next;
    }
};