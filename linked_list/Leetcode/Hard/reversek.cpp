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
 
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* curr = head;
        int length = 0;
        
        while (curr) {
            curr = curr->next;
            length++;
        }

        ListNode* prev = temp;
        curr = head;
        ListNode* next;

        while (length >= k) {
            
            for (int i = 1; i < k; i++) {
                next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            
            prev = curr;
            curr = curr->next;
            length -= k;
        }
        
        return temp->next;
    }
};