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

 //876
 /*note:- two pointer approach is better slow and fast (cuz f is moving 2 times the slow so when fast reaches the last ele . 
 the slow will be at middle position)*/

 //logic:- mine :- finc length then traverse till middle element and then return the val

 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* current = head;
        
        while (current != nullptr) {
            current = current->next;
            length++;
        }
        
        int steps_to_middle = length / 2;

        ListNode* mid = head;
        
        for (int i = 0; i < steps_to_middle; i++) {
            mid = mid->next;
        }

        return mid;
    }
};