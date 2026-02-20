class Solution {
public:
    char solve(int k)
    {
        if(k==1)
        {
            return 'a';
        }
        int len=1;
        while(len<k)
        {
            len=len*2;
        }
        
        
            char ch=solve(k-len/2);
            return ch+1;
        
    }
    char kthCharacter(int k) {
       return solve(k);

        
    }
};