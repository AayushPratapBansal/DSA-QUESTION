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
     ListNode*solve(ListNode*slow){
        ListNode*prev=NULL;
        ListNode*curr=slow;

        while(curr!=NULL){
        ListNode*next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;     
        }
        return prev;
     }
   

    int pairSum(ListNode* head) {
        ListNode*temp=head;
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            if(fast!=NULL) {
                fast=fast->next;
            }
        }
        ListNode*reversed=solve(slow);
       int maxi=INT_MIN;
       while(reversed!=NULL){
          maxi=max(maxi,reversed->val+temp->val);
         reversed=reversed->next;
         temp=temp->next;
       }
     return maxi;
    }
};