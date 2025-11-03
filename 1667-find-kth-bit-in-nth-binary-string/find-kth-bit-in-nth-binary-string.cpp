class Solution {
public:
    string invert(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
                s[i]='1';
            else
                s[i]='0';
        }
        return s;
    }
    string reverse(string s)
    {
        int st=0;
        int e=s.size()-1;
        while(st<e)
        {
            swap(s[st],s[e]);
            st++;
            e--;
        }
        return s;
    }
    string solve(int n,int k,string s)
    {
        s="0";
        for(int i=1;i<n;i++)
        {
            string val=invert(s);
            string val2=reverse(val);
            s=s+'1'+val2;
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string c;
        string s=solve(n,k,c);
        return s[k-1];

        
        
        
    }
};