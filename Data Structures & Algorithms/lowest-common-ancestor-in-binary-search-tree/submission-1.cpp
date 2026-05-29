/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* min = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool a = false;
        bool b = false;
        if(contains(root, p, q, a, b)){
            min = root;
            lowestCommonAncestor(root->left, p, q);
            lowestCommonAncestor(root->right, p, q);
        } 
        else{
            return nullptr;
        }
        return min;
    }
    bool contains(TreeNode* root, TreeNode* p, TreeNode* q, bool& pT, bool& qT) {
        if(pT && qT) return true;
        if(!root) return false;
        if(root->val == q->val) qT = true;
        else if(root->val == p->val) pT = true;
        contains(root->left, p, q, pT, qT);
        contains(root->right, p, q, pT, qT);
        return pT && qT;
    }
};
