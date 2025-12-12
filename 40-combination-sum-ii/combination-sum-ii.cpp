class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>&ans,long long sum,vector<int>&temp,int index)
    {
        
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(sum>target || index>=candidates.size())
            return;
        for(int i=index;i<candidates.size();i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
                
            if(candidates[i] > target - sum)              
                break;

            temp.push_back(candidates[i]);
            solve(candidates,target,ans,sum+candidates[i],temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates,target,ans,0,temp,0);
        
        return ans;
        
    }
};