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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector<vector<int>>ans;    queue<TreeNode*>q;
          if(root==NULL) return ans;
          q.push(root);
          vector<int>help;       bool flag=true;
          while(!q.empty()){
               int size=q.size();
               for(int i=0;i<size;i++){
                  TreeNode*curr=q.front(); q.pop();
                  if(curr->left!=NULL) q.push(curr->left);
                  if(curr->right!=NULL) q.push(curr->right);
                  help.push_back(curr->val);
               }
             if(!flag)  reverse(help.begin(),help.end());
             ans.push_back(help);
            flag=!flag;   help.clear();
          }
      return ans;
    }
};