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
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* buildTree(vector<int>&arr,int i)
    {
        if(i==arr.size())
            return NULL;
        TreeNode* root=new TreeNode(arr[i]);
        root->right=buildTree(arr,i+1);
        return root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return buildTree(ans,0);
        
    }
};