// Inserts nodes with the Greatest Common Divisor of 
// adjacent node values between them (note: C++ has an inbuilt 
// std::gcd() in <numeric>).
//ps:-2807. Insert Greatest Common Divisors in Linked List
class Solution {
public:
    int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            int gcdVal = gcd(curr->val, curr->next->val);
            
            ListNode* newNode = new ListNode(gcdVal);
            newNode->next = curr->next;
            curr->next = newNode;

            curr = newNode->next;
        }

        return head;
    }
};