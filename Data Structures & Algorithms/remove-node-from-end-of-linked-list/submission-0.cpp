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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            curr = curr->next;
            size+=1;
        }
        int indexToDelete = size - n;
        curr = head;
        if(indexToDelete == 0) return head->next;
        while(indexToDelete > 1){
            curr = curr->next;
            indexToDelete--;
        }
        curr->next = curr->next->next;
        return head;
        
    }
};
