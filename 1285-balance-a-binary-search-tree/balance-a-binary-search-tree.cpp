/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&inord)
    {
        if(root==NULL)
            return;
        inorder(root->left,inord);
        inord.push_back(root->val);
        inorder(root->right,inord);
        
        
    }
    TreeNode* makeTree(vector<int>&arr,int s,int e)
    {
        if(s>e)
            return NULL;
        int mid=(s+e)/2;
        TreeNode* temp=new TreeNode(arr[mid]);
        temp->left=makeTree(arr,s,mid-1);
        temp->right= makeTree(arr,mid+1,e);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inord;
        inorder(root,inord);
        int n=inord.size();
        TreeNode* Node=makeTree(inord,0,n-1);
        return Node;

        
    }
};