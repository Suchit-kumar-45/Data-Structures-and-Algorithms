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
    ListNode* solve(ListNode* &list1, ListNode* &list2)
    {
        ListNode* prev=list1;
        ListNode* curr=list1->next;
        ListNode* temp=list2;
        ListNode* temp2=temp->next;
        //if only one element is present in first LL
        if(list1->next==NULL)
        {
            list1->next=list2;
            return list1;
        }
        while(curr!=NULL && temp!=NULL)
        {
            if(temp->val >= prev->val && temp->val <= curr->val)
            {
                //addition of node in the first LL
                prev->next=temp;
                temp2=temp->next;
                temp->next=curr;
                //update the pointers
                prev=temp;
                temp=temp2;
            }
            //go one step ahead in list1
            else
            {
                prev=curr;
                curr=curr->next;
                if(curr==NULL)
                {
                    prev->next=temp;
                    return list1;
                }
            }
        }
        return list1;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        //always merge into the list with smaller atarting value
        if(list1->val > list2->val)
        {
           return solve(list2,list1);
        }
        else
        {
           return solve(list1,list2);
        }
       
       
        
    }
};