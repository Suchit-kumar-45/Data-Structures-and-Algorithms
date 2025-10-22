class Solution {
public:
    int solve(int n,vector<int>&dp)
    {
        if(n==1)
            return 1;

        if(dp[n]!=-1)
            return dp[n];
        for(int i=1;i<n;i++)
        {
            int nobreak=i*(n-i);
            int withbreak=i*solve(n-i,dp);
            dp[n]=max({dp[n],nobreak,withbreak});
        }
        return dp[n];
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);

        
    }
};