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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
       return helper (root, k, res);
    }
    int helper(TreeNode* root, int& k, int& res) {
        if(k == 0) return res;
        if(!root) return 0;
        helper(root->left, k, res);
        cout << root->val << " " << k << "\n";
        if(k == 1){
            k--;
            res = root->val;
            cout << res << " " << k;
            return res;
        } 
        k--;
        helper(root->right, k, res);
        return res;
    }
};
