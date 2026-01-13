class Solution {
public:
    vector<string>path;
    bool isPalindrome(string s,int start,int end)
    {
        while(start<end){
        if(s[start]!=s[end])
            return false;
        start++;
        end--;
        }
        return true;
    }
    void solve(string s,int index,vector<vector<string>>&ans)
    {
        if(index==s.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                solve(s,i+1,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        solve(s,0,ans);
        return ans;
    }
};