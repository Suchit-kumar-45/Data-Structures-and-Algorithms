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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(temp1 != NULL && temp2 != NULL)
        {
            int val1=temp1->val;
            int val2=temp2->val;
            int sum=carry+val1+val2;
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1 != NULL)
        {
            int val1=temp1->val;
            int sum=carry+val1;
            carry=sum/10;
            temp->next= new ListNode(sum%10);
            temp1=temp1->next;
            temp=temp->next;
        }
        while(temp2 != NULL)
        {
            int val2=temp2->val;
            int sum=carry+val2;
            carry=sum/10;
            temp->next= new ListNode(sum%10);
            temp2=temp2->next;
            temp=temp->next;
        }
        if(carry != 0)
        {
            temp->next=new ListNode(carry);
        }
        return dummy->next;

        
    }
};