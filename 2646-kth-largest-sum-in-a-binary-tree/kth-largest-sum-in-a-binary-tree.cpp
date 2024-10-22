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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long int>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           long long int sum=0; int size=q.size();
               for(int i=0;i<size;i++){
                 sum=sum+q.front()->val;
                 if(q.front()->left) q.push(q.front()->left);
                 if(q.front()->right) q.push(q.front()->right);
                  q.pop();
               }
               pq.push(sum);
        }
   for(int i=0;i<k-1;i++){
    if(pq.empty())   return -1;
        pq.pop();  
   }
     if(pq.empty()) return -1;

        // while(!pq.empty()&&k>0){
        //     if(k==1)   return pq.top();
        //     k--;
        //     pq.pop();
        // }


      return pq.top();
    }
};