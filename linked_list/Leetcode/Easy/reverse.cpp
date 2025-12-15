/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


 //206 - REVERSE LINKED LIST

//note:- always saves the next element , if to do operation with the previous one 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* current = head; 
        ListNode* next_original = nullptr; 

        while (current != nullptr) {
            
            next_original = current->next;
            
            current->next = newHead;
            
            newHead = current;
            
            current = next_original;
        }

        return newHead;
    } 
};