class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        int index=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                index=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==index)
                continue;
            if(2*nums[i]>maxi)
            {
                return -1;
            }
        }
        return index;
        
    }
};