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
   vector<string> solve(TreeNode* root,string s,vector<string>&arr)
    {
        if(!root->left && !root->right)
        {
            arr.push_back(s);
            //return arr;
        }
        if(root->left)
            solve(root->left,s+char(root->left->val+'0'),arr);
        if(root->right)
            solve(root->right,s+char(root->right->val+'0'),arr);
        return arr;
    }
    int sumNumbers(TreeNode* root) {
        string s;
        vector<string>arr;
        s+=char(root->val+'0');
        solve(root,s,arr);
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            int val=stoi(arr[i]);
            ans+=val;
        }
        return ans;

        
    }
};