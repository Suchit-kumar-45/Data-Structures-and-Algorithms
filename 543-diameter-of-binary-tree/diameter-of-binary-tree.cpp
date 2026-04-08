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
    //first-diameter and second-height
    pair<int,int> diameterFast(TreeNode* root)
    {
        if(root==NULL){
            pair<int,int>p={0,0};
            return p;
        }
        pair<int,int>leftAns=diameterFast(root->left);
        pair<int,int>rightAns=diameterFast(root->right);

        int left=leftAns.first;
        int right=rightAns.first;

        int height=leftAns.second+rightAns.second+1;

        pair<int,int>ans;
        ans.first=max({left,right,height});
        ans.second=max(leftAns.second,rightAns.second)+1;
        return ans;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first-1;
        
    }
};