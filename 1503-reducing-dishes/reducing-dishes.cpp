class Solution {
public:
//using tabulation
    int solve(vector<int>&sat)
    {
        int n=sat.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int time=n-1;time>=0;time--)
            {
                int incl=sat[index]*(time+1)+dp[index+1][time+1];
                int excl=0+dp[index+1][time];
                dp[index][time]=max(incl,excl);
            }
        }
        
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        
        return solve(satisfaction);   
    }
};