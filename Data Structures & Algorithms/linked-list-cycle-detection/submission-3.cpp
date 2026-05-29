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
    bool hasCycle(ListNode* head) {
     ListNode* prev = head;
     ListNode* curr = head;
     while(curr != nullptr && curr->next != nullptr){
        prev = prev->next;
        curr = curr->next->next;
        if (prev == curr) return true;
     }
     return false;
        
    }
};
