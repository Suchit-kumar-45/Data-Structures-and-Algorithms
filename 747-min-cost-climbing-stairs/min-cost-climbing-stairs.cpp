class Solution {
public:
    int solve(vector<int>&cost,int i,vector<int>&dp,int n)
    {
        if(i==n-1)
        {
            return cost[n-1];
        }
        if(i==n-2)
        {
            return cost[n-2];
        }
        if(dp[i]!=-1)
            return dp[i];
        dp[i]=cost[i]+min(solve(cost,i+1,dp,n),solve(cost,i+2,dp,n));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i=cost.size();
        vector<int>dp(i+1,-1);
        int ans=min(solve(cost,0,dp,i),solve(cost,1,dp,i));
        return ans;
        
    }
};