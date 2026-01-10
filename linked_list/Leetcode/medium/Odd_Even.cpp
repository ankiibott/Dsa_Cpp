/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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