class Solution {
public:
    int solve(vector<int>& coins, int amount,int index,vector<vector<int>>&dp)
    {
        if(index>=coins.size())
        {
            return 0;
        }
        if(amount==0)
            return 1;
        if(dp[amount][index]!=-1)
            return dp[amount][index];
            
        int ways=0;
        if(amount-coins[index]>=0)
             ways+=solve(coins,amount-coins[index],index,dp);
        ways+=solve(coins,amount,index+1,dp);

        return dp[amount][index]=ways;

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        return solve(coins,amount,0,dp);
        
    }
};