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