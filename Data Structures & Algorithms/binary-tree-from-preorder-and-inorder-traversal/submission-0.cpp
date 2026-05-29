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
    unordered_map<int, int> position;
    int index = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i < inorder.size() ; i++){
            position[inorder[i]] = i;
        }
        return construct(preorder, 0, inorder.size() - 1);

    }
    TreeNode* construct(vector<int>& preorder, int Inleft, int Inright){
        if(Inleft > Inright) return nullptr;
        int root = preorder[index];
        index++;
        TreeNode* rootC = new TreeNode(root);
        int mid = position[root];
        rootC->left = construct(preorder, Inleft, mid - 1);
        rootC->right = construct(preorder,mid + 1, Inright);
        return rootC;
    }
};
