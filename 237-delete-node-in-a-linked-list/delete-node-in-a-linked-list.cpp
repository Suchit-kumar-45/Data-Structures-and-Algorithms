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
    void deleteNode(ListNode* node) {
        ListNode* temp=node->next;
        //copy the value of temp in node so that the 5 is removed but it is not deleted from the memory
        node->val=temp->val;
        //point the node to the next of temp so that we can delete the temp
        node->next=temp->next;
        temp->next=NULL;
        delete(temp);


        
    }
};