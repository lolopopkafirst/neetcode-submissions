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
 
    stack<int> st;
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root , res);
        return res;
    }
    int dfs(TreeNode* root, int& res) {
        if(!root) return 0;
        if(st.empty()){
            st.push(root->val);
            res += 1;
        }
        else if(st.top() <= root->val){
            res += 1;
            st.push(root->val);
        }
        else {
            st.push(st.top());
        }
        
        int r = dfs(root->right, res);
        int l = dfs(root->left, res);
        if(r == 0 && l == 0) st.pop();
        return 0;
    }
};
