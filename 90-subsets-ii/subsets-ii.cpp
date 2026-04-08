class Solution {
public:
    void solve(vector<int>& nums,set<vector<int>>&ans,vector<int>temp,int i)
    {
        if(i>=nums.size())
        {
            ans.insert(temp);
            return;
        }
        //exclude
        solve(nums,ans,temp,i+1);

        //include
        temp.push_back(nums[i]);
        solve(nums,ans,temp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        vector<int>temp;
        int i=0;
        solve(nums,ans,temp,i);
        vector<vector<int>>res(ans.begin(),ans.end());
        
        
        return res;
    }
};