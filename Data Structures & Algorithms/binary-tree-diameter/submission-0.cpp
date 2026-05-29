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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        return help2(root, res);
         
    }
    int help2(TreeNode* root, int& res) {
        if(root == nullptr) return 0;
        res = max(res, help(root->left) + help(root->right));
        help2(root->left, res);
        help2(root->right, res);
        return res;
    }
    int help(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = help(root->left);
        int r = help(root->right);
        return max(l,r) + 1;
    }
};
