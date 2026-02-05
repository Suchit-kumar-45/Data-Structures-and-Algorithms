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
    vector<vector<int>>ans;
    void traverse(TreeNode* root,int level){
        if(!root)return;
        if(ans.size()==level){
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        traverse(root->left,level+1);
        traverse(root->right,level+1);

    }

    int deepestLeavesSum(TreeNode* root) {
        
        traverse(root,0);
        int sum=0;
        int x=ans.size()-1;
        int y=ans[x].size();
        for(int i=0;i<y;i++){
            sum+=ans[x][i];
        }
        return sum;

    }
};