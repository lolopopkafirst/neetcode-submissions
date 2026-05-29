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
    unordered_map <Node*, Node*> um;
    for(Node* i = head ; i ; i = i->next){
        um[i] = new Node(i->val);
    }
    for(Node* i = head ; i ; i = i->next){
        Node* copy = um[i];
        copy->next = um[i->next];
        copy->random = um[i->random];
    }
    return um[head];
    }
};
