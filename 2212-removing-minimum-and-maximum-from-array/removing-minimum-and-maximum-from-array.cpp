class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int index1=0,index2=0,n=nums.size();
        if(n==1)
            return 1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<mini)
            {
                mini=nums[i];
                index1=i;
            }
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                index2=i;
            }
        }
        if(index1>index2)
        {
            swap(index1,index2);
        }
        int op1=index2+1;
        int op2=n-index1;
        int op3=((index1+1)+(n-index2));
        return min({op1,op2,op3});
        
        
        


        
    }
};