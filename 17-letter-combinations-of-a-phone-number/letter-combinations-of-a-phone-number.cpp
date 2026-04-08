class Solution {
public:
    void solve(string digits,vector<string>&ans,string mapp[],string s,int index)
    {
        if(index>=digits.size())
        {
            ans.push_back(s);
            return ;
        }
        int value=digits[index]-'0';
        string temp=mapp[value];
        for(int i=0;i<temp.size();i++)
        {
            s.push_back(temp[i]);
            solve(digits,ans,mapp,s,index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string mapp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s;
        solve(digits,ans,mapp,s,0);
        return ans;
        
    }
};