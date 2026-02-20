class Solution {
public:
    char solve(int i,int k,string &s)
    {
        while(s.size()<k)
        {
            int size=s.size();
            for(int i=0;i<size;i++)
            {
                char ch=s[i]+1;
                s+=ch;
            }
            
        }
        return s[k-1];
    }
    char kthCharacter(int k) {
        string s="a";
       return solve(0,k,s);

        
    }
};