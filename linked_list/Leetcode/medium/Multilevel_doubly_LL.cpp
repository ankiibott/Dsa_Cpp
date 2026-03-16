/*
 * Logic: Flatten a multilevel doubly linked list.
 * - Iterate nodes point-by-point.
 * - When a child is found, disconnect the current 'next' branch and store it in a 'dummy' list.
 * - Make the child the new 'next' node and clear the child pointer.
 * - Upon reaching the end of the current branch, attach any stashed nodes from the 'dummy' list.
 */
//ps:-430. Flatten a Multilevel Doubly Linked List
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;
        Node* dummy = new Node();

        while (temp != nullptr) {
            if (temp->child != nullptr) {
                if (temp->next != nullptr) {
                    Node* nextPart = temp->next;
                    Node* currentStored = dummy->next;

                    Node* newPartTail = nextPart;
                    while (newPartTail->next != nullptr) {
                        newPartTail = newPartTail->next;
                    }

                    if (currentStored != nullptr) {
                        newPartTail->next = currentStored;
                        currentStored->prev = newPartTail;
                    }

                    dummy->next = nextPart;
                    nextPart->prev = dummy;
                }

                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = nullptr;
            }

            if (temp->next == nullptr && dummy->next != nullptr) {
                Node* stored = dummy->next;
                temp->next = stored;
                stored->prev = temp;
                
                dummy->next = nullptr;
            }

            temp = temp->next;
        }
        
        delete dummy;
        return head;
    }
};