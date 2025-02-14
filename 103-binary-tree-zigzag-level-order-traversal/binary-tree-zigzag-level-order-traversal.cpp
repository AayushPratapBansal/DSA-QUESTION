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
            
             vector<vector<int>>ans;
             if(!root)  return ans;
              vector<int>arr;
              queue<TreeNode*>q;
              q.push(root);
              bool flag=true;
              while(!q.empty()){
                    int size=q.size();
                    for(int i=0;i<size;i++){
                         TreeNode*curr=q.front();    q.pop();
                         if(curr->left)  q.push(curr->left);
                         if(curr->right)  q.push(curr->right);
                          arr.push_back(curr->val);
                   }
                   if (!flag) reverse(arr.begin(), arr.end());

                    ans.push_back(arr);
                    arr.clear(); 
                   flag =!flag;
              }

          return ans;
    }
};