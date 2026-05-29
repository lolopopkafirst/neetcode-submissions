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
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, -101, res);
        return res;
    }
    void dfs(TreeNode* root, int maxRN, int& res) {
        if(!root) return;
        if(maxRN == -101){
            res += 1;
            maxRN = root->val;
            cout << maxRN;
        }
        else if(maxRN <= root->val){
            res += 1;
            maxRN = root->val;
        }
        dfs(root->right, maxRN, res);
        dfs(root->left, maxRN, res);
    }
};
