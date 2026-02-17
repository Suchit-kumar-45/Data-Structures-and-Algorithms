class Solution {
public:
    void solve(string &s, int i,int n,vector<string>&ans)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        if(isalpha(s[i]))
        {
                
                s[i]=tolower(s[i]);
                solve(s,i+1,n,ans);
            
                s[i]=toupper(s[i]);
                solve(s,i+1,n,ans);
            
        }
        else
        {
            solve(s,i+1,n,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        vector<string>ans;
        solve(s,0,n,ans);
        return ans;
        
    }
};