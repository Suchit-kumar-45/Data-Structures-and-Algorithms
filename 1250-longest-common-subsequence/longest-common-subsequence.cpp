class Solution {
public:
    int solve(string text1, string text2)
    {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int index1=n1-1;index1>=0;index1--)
        {
            for(int index2=n2-1;index2>=0;index2--)
            {
                int incl=0;
                if(text1[index1]==text2[index2])
                {
                     incl=1+dp[index1+1][index2+1];
                }
                int excl1=0+dp[index1+1][index2];
                int excl2=0+dp[index1][index2+1];
                dp[index1][index2]= max({incl,excl1,excl2});
            }
        }
        
        
        
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        return solve(text1,text2);
        
    }
};