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
    int minimal = 0;
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return minimal >= 2 ? false : true;
    }
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        minimal = max(((l - r) < 0 ? (r - l) : (l - r)) , minimal);
        return max(l, r) + 1;
    }
};
