class Solution {
public:
    int bitwiseComplement(int n) {
        int num=n;
        vector<int> ans;
        if(n==0)
            return 1;
        while(num>1)
        {
            if(num%2==1)
            {
                ans.push_back(1);
            }
            else
            {
                ans.push_back(0);
            }
            num=num/2;
        }
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==1)
            {
                ans[i]=0;
            }
            else
            {
                ans[i]=1;
            }
        }
        int val=0;
        for(int i=ans.size()-1;i>=0;i--)
        {
            val+=ans[i]*pow(2,i);
        }
        return val;
        
    }
};