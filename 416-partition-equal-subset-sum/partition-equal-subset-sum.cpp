class Solution {
public:
    bool solve(vector<int>&nums,double sum,int i,vector<vector<int>>&dp)
    {
        if(sum==0)
            return true;
        if(i==nums.size())
             return false;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        bool include=false;
        
        if(nums[i]<=sum)
            include=solve(nums,sum-nums[i],i+1,dp);
        bool exclude=solve(nums,sum,i+1,dp);
        dp[i][sum]=include||exclude;
            
        return dp[i][sum];
        
       
        
    }
    bool canPartition(vector<int>& nums) {
        double sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(nums,sum/2,0,dp);
        
    }
};