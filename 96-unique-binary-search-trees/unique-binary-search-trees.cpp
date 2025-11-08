class Solution {
public:
    int solve(int n,vector<int>&dp)
    {
        if(n==1 || n==0)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int total=0;
        //left me minus one kar denge and right me n-root kar denge 
        for(int root=1;root<=n;root++)
        {
        int left=root-1;
        int right=n-root;
        total+=solve(left,dp)*solve(right,dp);
        }
         dp[n]=total;
         return dp[n];
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
        
    }
};