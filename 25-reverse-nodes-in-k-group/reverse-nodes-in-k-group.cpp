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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
  // TO FIND LENGTH OF THE LINKED LIST
  int len=0;   ListNode*poin=head;
  while(poin!=NULL){
    len++;
    poin=poin->next;
  }

  if(k>len){
    return head;
  }



        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*currnext;
        ListNode*temp;
        int i=0;

        while(i<k&&curr!=NULL){
            currnext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=currnext;
            i++;
        
        }
        temp=reverseKGroup(curr,k);
        head->next=temp;
        return prev;

    }
};