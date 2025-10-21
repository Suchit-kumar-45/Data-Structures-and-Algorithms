class Solution {
public:
    int solve(vector<int>& nums,int n,int start,vector<int>&dp)
    {
        if(n==start)
            return nums[start];
        if(n<start)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        
        int incl=solve(nums,n-2,start,dp)+nums[n];
        int excl=solve(nums,n-1,start,dp)+0;
        dp[n]=max(incl,excl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp1(n,-1);
        int ans1=solve(nums,n-1,1,dp1);

        vector<int>dp2(n,-1);
        int ans2=solve(nums,n-2,0,dp2);
        
        return max(ans1,ans2);
    }
};