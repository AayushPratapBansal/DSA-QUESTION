/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool flag=false;
        if(head==NULL||head->next==NULL)  return flag;
  
      ListNode*fast=head,*slow=head;

      while(fast&&fast->next){
          fast=fast->next->next;
          slow=slow->next;
          if(fast==slow){
            return true;
          }
      }
        return flag;
    }
};