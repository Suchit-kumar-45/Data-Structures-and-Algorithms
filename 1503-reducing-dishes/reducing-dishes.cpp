class Solution {
public:
//using memoization
    int solve(vector<int>&sat,int index,int time,vector<vector<int>>&dp)
    {
        //base case
        if(index==sat.size())
            return 0;
        if(dp[index][time]!=-1)
            return dp[index][time];
        int incl=sat[index]*(time+1)+solve(sat,index+1,time+1,dp);
        int excl=0+solve(sat,index+1,time,dp);
        return dp[index][time]=max(incl,excl);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(satisfaction,0,0,dp);   
    }
};