class Solution {
public:
    int zerocount(string s)
    {
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                count++;
            }
        }
        return count;
    }
    int onecount(string s)
    {
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                count++;
            }
        }
        return count;
    }
    int solve(vector<string>& strs, int m, int n,int index,vector<vector<vector<int>>>&dp)
    {
        if(index==strs.size())
            return 0;
        if(dp[m][n][index]!=-1)
        {
            return dp[m][n][index];
        }
        int incl=0;
        int zcount=zerocount(strs[index]);
        int ocount=onecount(strs[index]);
        if(zcount<=m && ocount<=n)
        {
            incl=1+solve(strs,m-zcount,n-ocount,index+1,dp);
        }
        int excl=0+solve(strs,m,n,index+1,dp);

        dp[m][n][index]= max(incl,excl);
        return dp[m][n][index];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return solve(strs,m,n,0,dp);
        
    }
};