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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*temp=new ListNode(-1); temp->next=head;
        ListNode*forw=temp;
        ListNode*prev=temp;
         ListNode*curr=head;
     if(head==NULL||head->next==NULL)  return head;
        
        while(curr!=NULL){
             if(curr->next!=NULL&&curr->val==curr->next->val) {
                
                  while(curr->next!=NULL&&curr->val==curr->next->val){
                    curr=curr->next;
                  }
                  prev->next=curr->next;
             }
             else prev=curr;
             curr=curr->next;
        }
         return forw->next;
    }
};