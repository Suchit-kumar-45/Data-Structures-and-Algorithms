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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>arr(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                int index=0;
                if(leftToRight)
                {
                    index=i;
                }
                else
                {
                    index=(size-i-1);
                }
                arr[index]=front->val;
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
            ans.push_back(arr);  
            leftToRight=!leftToRight;          
        }
    return ans;
        
    }
};