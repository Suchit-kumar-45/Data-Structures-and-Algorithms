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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1)
            return {new TreeNode(0)};
        vector<TreeNode*>ans;
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left=allPossibleFBT(i);
            vector<TreeNode*> right=allPossibleFBT(n-i-1);

            for(auto j:left)
            {
                for(auto k:right)
                {
                    TreeNode* root=new TreeNode();
                    root->left=j;
                    root->right=k;
                    ans.push_back(root);
                }
            }

        }
        return ans;
        
    }
};