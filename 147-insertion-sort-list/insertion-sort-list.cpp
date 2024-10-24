/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    if(head==NULL)  return head;
    vector<int>ans;
    ListNode*curr=head;
    while(curr!=NULL){
          ans.push_back(curr->val);
          curr=curr->next;
    }
    sort(ans.begin(),ans.end());
    ListNode*temp=new ListNode(-1);
    ListNode*point=temp;
         for(int i=0;i<ans.size();i++){
            ListNode*curr=new ListNode(ans[i]);
            point->next=curr;
            point=point->next;
         }
   return temp->next;
    }
};