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
    void solve(TreeNode*root){
       if(root==NULL) return;
    TreeNode*rr=root->right;
    root->right=root->left;
    root->left=rr;
    solve(root->left);
    solve(root->right);

    }
    TreeNode* invertTree(TreeNode* root) {
       solve(root);
 return root;               
    }
};