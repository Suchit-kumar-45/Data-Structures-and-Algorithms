class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>&ans,int i,vector<int>temp)
    {
        if(i>=candidates.size() || target<0)
        {
            return;
        }
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
            temp.push_back(candidates[i]);
            //same index
            solve(candidates,target-candidates[i],ans,i,temp);
            //backtrack
            temp.pop_back();
            //next index
            solve(candidates,target,ans,i+1,temp);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int i=0;
        vector<int>temp;
        solve(candidates,target,ans,i,temp);
        return ans;
        
    }
};