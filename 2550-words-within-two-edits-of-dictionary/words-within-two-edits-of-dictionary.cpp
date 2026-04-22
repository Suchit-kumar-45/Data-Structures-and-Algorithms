class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int m=queries.size();
        int n=dictionary.size();
        vector<string>ans;
        for(int i=0;i<m;i++)
        {
            string s=queries[i];
            for(int j=0;j<n;j++)
            {
                string st=dictionary[j];
                int count=0;
                for(int k=0;k<s.size();k++)
                {
                    if(s[k] != st[k])
                    {
                        count++;
                    }
                }
                if(count<=2)
                {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
        
    }
};