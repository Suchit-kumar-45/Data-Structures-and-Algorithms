class Solution {
public:
    int solve(vector<int>& slices,int index,int endindex,int n,vector<vector<int>>&dp)
    {
        if(n==0 || index>endindex)
            return 0;
        if(dp[index][n] != -1)
            return dp[index][n];
        int incl=slices[index]+solve(slices,index+2,endindex,n-1,dp);
        int excl=0+solve(slices,index+1,endindex,n,dp);
        dp[index][n]= max(incl,excl);
        return dp[index][n];
        
    }
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        vector<vector<int>>dp1(k+1,vector<int>(k/3+1,-1));
        vector<vector<int>>dp2(k+1,vector<int>(k/3+1,-1));
        int ans1=solve(slices,0,k-2,k/3,dp1);
        int ans2=solve(slices,1,k-1,k/3,dp2);
        return max(ans1,ans2);
        
    }
};