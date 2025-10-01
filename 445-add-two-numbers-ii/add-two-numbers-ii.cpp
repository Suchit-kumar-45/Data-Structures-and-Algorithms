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
    void insert(ListNode * &head,ListNode* &node,int data)
    {
        ListNode* temp=new ListNode(data);
        if(head==NULL)
        {
            head=temp;
            node=head;
        }
        else
        {
            node->next=temp;
            node=node->next;
        }
    }
    ListNode* addList(ListNode* &l1, ListNode* &l2)
    {
        int carry=0;
        ListNode* ansNode=NULL;
        ListNode* node=NULL;
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int val1=0;
            if(l1 != NULL)
            {
                val1=l1->val;
            }
            int val2=0;
            if(l2 != NULL)
            {
                val2=l2->val;
            }
            int sum=val1+val2+carry;
            int digit=sum%10;
            insert(ansNode,node,digit);
            carry=sum/10;

            if(l1 != NULL)
            {
                l1=l1->next;
            }
            if(l2 != NULL)
            {
                l2=l2->next;
            }

        }
        return ansNode;
        

    }
    void reverseList(ListNode* &head)
    {
        if(head==NULL)
            return;
        ListNode* prev=NULL;
        while(head!=NULL)
        {
            ListNode* temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        head=prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=l1;
        ListNode* head2=l2;
        reverseList(head1);
        reverseList(head2);

        ListNode* ans=addList(head1,head2);
        reverseList(ans);
        return ans;

        
    }
};