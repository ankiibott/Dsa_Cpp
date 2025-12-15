/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x, next) {}
 * };
 */

 //19. Remove Nth Node From End of List
//note :- worst case humesha phle hi sochlo aur uske liye ek alag se if() dedo like n==len
//logic :- find len then trav till len-n from head and then perform deletion


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp != nullptr){
            len++;
            temp = temp->next;
        }

        if(head == nullptr || len == 0){
            return nullptr;
        }

        if (n == len) {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return head;
        }
        int steps_to_prev = len - n; 
        
        ListNode* temp1 = head;
        ListNode* prev = nullptr; 

        for(int i = 0; i < steps_to_prev; i++) {
            prev = temp1;
            temp1 = temp1->next; 
        }
        prev->next = temp1->next;
        temp1->next = nullptr;
        delete temp1;

        return head;
    }
};