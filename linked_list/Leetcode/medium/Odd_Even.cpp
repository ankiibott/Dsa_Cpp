//logic:- always take two pointers only and a temp to store if needed some connection
//ps:- 328-ODD EVEN linked list

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *odd=head;
        ListNode *even=head->next;
        ListNode *temp=head->next;
        while(odd->next && even->next){xs54 
            odd->next=even->next;
            even->next=odd->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=temp;
        return head;
    }
};                 