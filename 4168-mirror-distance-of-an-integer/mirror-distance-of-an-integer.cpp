class Solution {
public:
    int mirrorDistance(int n) {
        int num=n;
        int res=0;
        while(num>0)
        {
            int digit=num%10;
            res=res*10+digit;
            num=num/10;
        }
        return abs(n-res);
        
    }
};