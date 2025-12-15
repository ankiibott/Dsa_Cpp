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

 //234-Palindrom
 //note:- two pointers for comparing both the list
 //logic :- reverse (inserAtHead) and then comparison

 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* current = head;
        ListNode* reversed_head = nullptr;

        while (current != nullptr) {
            ListNode* newNode = new ListNode(current->val);
            newNode->next = reversed_head;
            reversed_head = newNode;
            current = current->next;
        }
        ListNode* original_ptr = head;
        ListNode* reversed_ptr = reversed_head;

        while (original_ptr != nullptr) {
            if (original_ptr->val != reversed_ptr->val) {
                return false;
            }
            original_ptr = original_ptr->next;
            reversed_ptr = reversed_ptr->next;
        }
        return true;
    }
};
