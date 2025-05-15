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

   ListNode* reverse(ListNode*slow){
        ListNode*curr=slow;
            ListNode*prev=NULL;
            while(curr!=NULL){
                     ListNode*next=curr->next;
                     curr->next=prev;
                     prev=curr;
                     curr=next;
            }
            return prev;       
    }

    bool isPalindrome(ListNode* head) {
         if(head==NULL||head->next==NULL)
         return true;
     ListNode*fast=head ,*slow=head;
            
             while(fast&&fast->next){
                slow=slow->next;
                fast=fast->next->next;
                }


     ListNode*secondhalf=reverse(slow);
     ListNode*firsthalf=head;

      while(secondhalf){
        if(firsthalf->val!=secondhalf->val)
              return false;
              firsthalf=firsthalf->next;
              secondhalf=secondhalf->next;
      }

 
return true;
               

        

    }
};