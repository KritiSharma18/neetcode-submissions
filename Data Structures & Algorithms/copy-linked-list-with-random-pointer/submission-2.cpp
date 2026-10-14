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
        unordered_map<Node*, Node*> copy;
        copy[nullptr] = nullptr;

        // Pass 1: create a copy of every node
        for (Node* cur = head; cur; cur = cur->next)
            copy[cur] = new Node(cur->val);

        // Pass 2: wire up next and random
        for (Node* cur = head; cur; cur = cur->next) {
            copy[cur]->next = copy[cur->next];
            copy[cur]->random = copy[cur->random];
        }
        return copy[head];
    }
};
