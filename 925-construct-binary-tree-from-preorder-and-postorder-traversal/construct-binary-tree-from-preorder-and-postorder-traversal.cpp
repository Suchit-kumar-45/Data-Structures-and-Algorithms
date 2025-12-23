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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,int &index, int postStart,int postEnd,int n)
    {
        if(index>=n || postStart>postEnd)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index++]);

         // check for leaf node
         if(postStart==postEnd)
            return root;
            
        int next=preorder[index];
        //search for next in postorder
        int i=postStart;
        while(postorder[i]!=next)
        {
            i++;
        }
        //recursive call
        root->left=solve(preorder,postorder,index,postStart,i,n);
        root->right=solve(preorder,postorder,index,i+1,postEnd-1,n);
        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preindex=0;
        int n=preorder.size();
        return solve(preorder,postorder,preindex,0,n-1,n);
        
    }
};