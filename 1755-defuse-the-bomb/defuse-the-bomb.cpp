class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n);
        if(k==0)
        {
            vector<int>arr(n,0);
            return arr;
        }
        else if(k>0)
        {
            int j=0;
            int sum=0;
            while(j<k)
            {
                sum+=code[j];
                j++;
            }
            for(int i=0;i<n;i++)
            {
                
                    sum=sum-code[i]+code[j];
                    ans[i]=sum;
                    j++;
                    if(j>=n)
                    {
                        j=j%n;
                    }
            }
        }
        else
        {
            int j=n-1;
            int sum=0;
            while(j>=(n-abs(k)))
            {
                sum+=code[j];
                j--;
            }
            j++;
            ans[0]=sum;
            for(int i=1;i<n;i++)
            {
                
                    sum=sum+code[i-1]-code[j];
                    ans[i]=sum;
                    j++;
                    if(j>=n)
                    {
                        j=j%n;
                    }
            }
        }
        return ans;
        
    }
};