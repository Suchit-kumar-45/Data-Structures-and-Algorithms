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
    int i=1;
    long long solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        long long ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            long long size=q.size();
            long long base=q.front().second;
            long long first=0,last=0;
            for(int i=0;i<size;i++)
            {
                pair<TreeNode*,long long> front=q.front();
                q.pop();
                TreeNode* node=front.first;
                long long index=front.second-base;
                if(i==0)
                    first=index;
                if(i==size-1)
                    last=index;
                if(node->left)
                {
                    q.push(make_pair(node->left,2*index+1));
                }
                if(node->right)
                {
                    q.push(make_pair(node->right,2*index+2));
                }
            }
            ans=max(ans,last-first+1);
            
        }
        return ans;
        
    }
    int widthOfBinaryTree(TreeNode* root) {
       return solve(root);
        
    }
};