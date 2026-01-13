class Solution {
public:
    int solve(string word1, string word2,int s1,int s2,vector<vector<int>>&dp)
    {
        if(s1==word1.size())
        {
            return word2.size()-s2;
        }
        if(s2==word2.size())
        {
            return word1.size()-s1;
        }
        if(dp[s1][s2]!=-1)
        {
            return dp[s1][s2];
        }
        if(word1[s1]==word2[s2])
        {
            return solve(word1,word2,s1+1,s2+1,dp);
        }

        int op1=1+solve(word1,word2,s1+1,s2,dp);
        int op2=1+solve(word1,word2,s1,s2+1,dp);
        int op3=1+solve(word1,word2,s1+1,s2+1,dp);
        dp[s1][s2]=min({op1,op2,op3});
        return dp[s1][s2];
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(word1,word2,0,0,dp);
        
    }
};