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

        if(!head || !head->next)
            return head;
        ListNode* curr=head;
        ListNode* temp=NULL;
        ListNode* prev=NULL;
        while(curr != NULL)
        {
            if(curr->val<x)
            {
                if(temp==NULL)
                {
                    if(prev != NULL){
                    prev->next=curr->next;
                    curr->next=head;
                    head=curr;
                    curr=prev->next;
                    }
                    else
                    {
                        curr=curr->next;
                    }
                    temp=head;
                    continue;
                }
                if(temp->next==curr)
                {
                    temp=curr;
                    prev=curr;
                    curr=curr->next;
                }
                else{
                    prev->next=curr->next;
                    curr->next=temp->next;
                    temp->next=curr;
                
                    temp=curr;
                    curr=prev->next;
                
                    
                }
                
            }
            else
            {
                prev=curr;
                curr=curr->next;
                
            }
        }
        return head;

        
    }
};