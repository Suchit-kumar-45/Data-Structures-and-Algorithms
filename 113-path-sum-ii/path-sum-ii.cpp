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
    void solve(TreeNode* root,int target,vector<int> path,vector<vector<int>> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        path.push_back(root->val);
        solve(root->left,target,path,ans);
        solve(root->right,target,path,ans);

        int size=path.size();
        int sum=0;
        for(int i=0;i<size;i++)
        {
            sum+=path[i];
        }
        if(sum==target && root->left==NULL && root->right==NULL)
            {
                ans.push_back(path);
            }
        //path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ans;
        solve(root,targetSum,path,ans);
        return ans;
        
    }
};