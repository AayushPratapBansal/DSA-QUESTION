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
    // bool flag=false;
    bool solve(TreeNode*root,int sum, int target){
         if(root==NULL) return false; 
         sum+=root->val;  
         if(root->left==NULL&&root->right==NULL){
         if(sum==target)  return true;
         else return false;
         }
         bool left=solve(root->left,sum,target);
         bool right=solve(root->right,sum,target);
         
         return left||right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // bool flag= false;
        int sum=0;
        return solve(root,sum,targetSum);
        
    }
};