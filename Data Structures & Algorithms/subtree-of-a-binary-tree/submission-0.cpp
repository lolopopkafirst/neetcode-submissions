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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if(!root) return false;
            if(equal(root, subRoot)) return true;
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool equal(TreeNode* root, TreeNode* subRoot) {
        if(root == subRoot) return true;
        else if(root == nullptr && subRoot != nullptr) return false;
        else if(root != nullptr && subRoot == nullptr) return false;
        if(root->val != subRoot->val) return false;
        return equal(root->left, subRoot->left) && equal(root->right, subRoot->right);
    }
};
