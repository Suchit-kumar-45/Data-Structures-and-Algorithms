class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(s.size()>2)
        {
            string ans="";
            int size=s.size();
            for(int i=0;i<size-1;i++)
            {
                int num1=s[i]-'0';
                int num2=s[i+1]-'0';
                int newnum=(num1+num2)%10;
                ans+=(newnum+'0');
            }
            s=ans;
        }
        if(s[0]==s[1])
        {
            return true;
        }
        return false;
        
    }
};