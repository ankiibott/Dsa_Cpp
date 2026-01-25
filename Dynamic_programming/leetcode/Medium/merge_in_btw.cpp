class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = list1;
        for(int i = 0; i < a - 1; i++) {
            start = start->next;
        }
        
        ListNode* end = start;
        for(int i = 0; i < b - a + 1; i++) {
            end = end->next;
        }
        
        ListNode* tail2 = list2;
        while(tail2->next != nullptr) {
            tail2 = tail2->next;
        }
        
        start->next = list2;
        tail2->next = end->next;
        
        return list1;
    }
};