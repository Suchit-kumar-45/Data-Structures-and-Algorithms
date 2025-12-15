class Solution {
public:
    bool solve(string s,vector<string>&worddict,int index,vector<int>&dp)
    {
        if(index==s.size())
        {
            return true;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
         for (string &word : worddict) {
            int len = word.length();

            // check bounds and match
            if (index + len <= s.size() &&
                s.compare(index, len, word) == 0) {

                if(solve(s, worddict, index + len,dp))
                    return dp[index]=true;
            }
        }
        return dp[index]=false;
        
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        return solve(s,wordDict,0,dp);
    }
};