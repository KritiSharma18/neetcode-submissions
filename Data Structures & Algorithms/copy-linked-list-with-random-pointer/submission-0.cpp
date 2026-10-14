/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. Insert each copy right after its original: A -> A' -> B -> B' ...
        for (Node* cur = head; cur; cur = cur->next->next) {
            Node* c = new Node(cur->val);
            c->next = cur->next;
            cur->next = c;
        }

        // 2. Set randoms: copy of X->random is X->random->next
        for (Node* cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;

        // 3. Separate the two lists, restoring the original
        Node* newHead = head->next;
        for (Node* cur = head; cur; cur = cur->next) {
            Node* c = cur->next;
            cur->next = c->next;
            if (c->next) c->next = c->next->next;
        }
        return newHead;
    }
};
