class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        string ans=s;
        if(s.size() != goal.size())
            return false;
        for(int i=0;i<n;i++)
        {
            ans+=s[i];
        }
        if(ans.find(goal) != string::npos)
        {
            return true;
        }
        return false;

        
    }
};