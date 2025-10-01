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
private:
    void insertAtTail(ListNode* &head,ListNode* &tail,int value)
    {
        ListNode* temp=new ListNode(value);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
private:
    ListNode* add(ListNode* head1,ListNode* head2)
    {
        int carry=0;
        ListNode* ansHead=NULL;
        ListNode* ansTail=NULL;
        while(head1 != NULL || head2!=NULL || carry!=0)
        {
            int val1=0;
            if(head1!=NULL)
            {
                val1=head1->val;
            }
            int val2=0;
            if(head2!=NULL)
            {
                val2=head2->val;
            }
           
            int sum=carry + val1 + val2;
            int digit=sum%10;
            //create node and add in answer LL
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            if(head1 != NULL)
            {
            head1=head1->next;
            }
            if(head2 !=NULL)
            {
            head2=head2->next;
            }
        }
       
        return ansHead;
    }
private:
ListNode* reverse(ListNode* l1)
{
    ListNode* curr=l1;
    ListNode* prev=NULL;
    ListNode* temp=NULL;
    while(curr != NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    } 
    return prev;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reverse given LL
    //    ListNode* head1= reverse(l1);
    //    ListNode* head2= reverse(l2);
       // sum two LL
       ListNode* ans=add(l1,l2);
       //reverse the added LL
    //    return reverse(ans);
    return ans;

        
    }
};