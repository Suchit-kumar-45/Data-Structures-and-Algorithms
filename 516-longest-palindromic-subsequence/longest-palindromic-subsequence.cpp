class Solution {
public:
    int solve(int i,int j,string &s,string &str,vector<vector<int>>&dp)
    {
        if(i>=s.size() || j>=str.size())
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==str[j])
        {
            ans=1+solve(i+1,j+1,s,str,dp);
        }
        else
        {
            ans= max(solve(i+1,j,s,str,dp),solve(i,j+1,s,str,dp));
        }
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        string newstr=s;
        reverse(newstr.begin(),newstr.end());
        return solve(0,0,s,newstr,dp);
        
    }
};