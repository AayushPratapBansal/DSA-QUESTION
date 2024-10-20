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
    ListNode* partition(ListNode* head, int x) {
        ListNode*temp1=new ListNode(-1);  ListNode*head1=temp1;
        ListNode*temp2=new ListNode(-1);   ListNode*head2=temp2;


        while(head!=NULL){
            if(head->val<x){
                temp1->next=head;
                temp1=temp1->next;   
            }
            else{
                temp2->next=head;
                temp2=temp2->next;
            }  
            head=head->next;
        }
        temp2->next=NULL;
        temp1->next=head2->next;
        return head1->next;
 
     


    }
};