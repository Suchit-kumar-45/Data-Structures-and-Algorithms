class Solution {
public:
    int solve(vector<int>&nums,int s,int e,vector<int>&dp)
    {
        if(s>e)
            return 0;

        if(s==e)
            return nums[e];
        if(dp[s]!=-1)
            return dp[s];
        int incl=nums[s]+solve(nums,s+2,e,dp);
        int excl=solve(nums,s+1,e,dp);
        return dp[s]=max(incl,excl);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int ans1=solve(nums,0,n-2,dp1);
        int ans2=solve(nums,1,n-1,dp2);
        return max(ans1,ans2);
        
    }
};