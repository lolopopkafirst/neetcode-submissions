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
    vector<int> res;

    vector<int> rightSideView(TreeNode* root) {
        helper(root, 0);
        return res;
    }

    void helper(TreeNode* a, int depth) {
       if(!a) return;
       
       if(depth == res.size()){
            res.push_back(a->val);
       }
        helper(a->right, depth + 1);
        helper(a->left, depth + 1);
    }
};
