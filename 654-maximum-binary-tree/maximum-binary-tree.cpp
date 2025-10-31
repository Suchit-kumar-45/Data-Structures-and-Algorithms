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
    int findmid(vector<int>&nums,int s,int e)
    {
        int maxi=INT_MIN;
        int index=0;
        for(int i=s;i<=e;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                index=i;
            }
        }
        return index;
    }
    TreeNode* solve(vector<int>& nums,int s,int e)
    {
        if(s>e)
            return NULL;
        int index=findmid(nums,s,e);
        TreeNode* root=new TreeNode(nums[index]);
        root->left=solve(nums,s,index-1);
        root->right=solve(nums,index+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n-1);
        
    }
};