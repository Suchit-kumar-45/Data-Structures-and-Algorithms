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
    TreeNode* LCA(TreeNode* a,TreeNode* b,TreeNode* root)
    {
        if(root==NULL)
            return NULL;
        if(root==a || root==b)
        {
            return root;
        }
        TreeNode* left=LCA(a,b,root->left);
        TreeNode* right=LCA(a,b,root->right);
        if(left != NULL && right==NULL)
            return left;
        else if(left==NULL && right!=NULL)
            return right;
        else if(left!=NULL && right!=NULL)
            return root;
        else
            return NULL;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>path;
        while(!q.empty())
        {
            int size=q.size();
            path.clear();
            for(int i=0;i<size;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                path.push_back(front);
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
            
        }
        TreeNode* ans=path[0];
        for(int i=1;i<path.size();i++)
            ans= LCA(ans,path[i],root);

        return ans;
        
    }
};