class Solution {
public:
    int solve(vector<int>&prices,int index,vector<int>&dp)
    {
        int n=prices.size();
        if(index>=prices.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
            return dp[index];
        int ans=INT_MAX;
        for(int i=index+1;i<=2*index+2;i++)
        {
            ans=min(ans,solve(prices,i,dp));
        }
        dp[index]= ans+prices[index];
        return dp[index];

    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n+1,-1);
        return solve(prices,0,dp);
        
    }
};