/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<int, Node*> um;
        return helper(node, new Node(), um);
    }
    Node* helper(Node*& node, Node* curr, unordered_map<int, Node*>& um){
        curr->val = node->val;
        um[curr->val] = curr;
        vector<Node*> newNeighbors;
        for(auto& nd : node->neighbors){
            if(um.find(nd->val) == um.end()){
                newNeighbors.push_back(helper(nd, new Node(), um));
            }
            else{
                newNeighbors.push_back(um[nd->val]);
            }
        }
        curr->neighbors = newNeighbors;
        return curr;
    }
};
