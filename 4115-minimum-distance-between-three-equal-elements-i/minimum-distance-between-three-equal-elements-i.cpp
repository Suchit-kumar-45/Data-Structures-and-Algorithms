class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=1e9;
        for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                    {
                        for(int k=j+1;k<n;k++)
                            {
                                if(nums[i]==nums[j] && nums[j]==nums[k])
                                {
                                   int temp=abs(i-j)+abs(j-k)+abs(k-i);
                                    ans=min(ans,temp);
                                }
                            }
                    }
            }
        if(ans==1e9)
            return -1;
        else
            return ans;
        
    }
};