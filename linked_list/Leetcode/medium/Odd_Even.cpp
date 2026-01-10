
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;

        ListNode* curr = head;
        ListNode* nprev = curr;
        ListNode* prev = NULL;

        while(curr->next!=NULL){
            nprev = curr;
            prev = curr->next;
            curr = prev->next;
            
            //curr and nprev at odd position
            ListNode* store = prev;
            nprev->next = prev->next;
            store->next = curr->next;
            curr->next = store;
        }
    }
};