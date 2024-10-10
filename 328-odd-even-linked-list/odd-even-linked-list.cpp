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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*odd=new ListNode(-1);  ListNode*head1=odd;  
        ListNode*even=new ListNode(-1);  ListNode*head2=even;
        ListNode*temp=head;   int i=1;
      if(head==NULL||head->next==NULL||head->next->next==NULL)   return  head;
         
           while(temp!=NULL){
               if(i%2!=0) { odd->next=temp;   odd=odd->next;   }
               else{ even->next=temp;   even=even->next;}
               temp=temp->next;
               i++;
           }
     even->next=NULL;
      odd->next=head2->next;

   return head1->next;
    }
};