class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        long long p=1;
        if(k<=1)
            return 0;
        int i=0,j=0;
        while(j<n)
        {
            p=p*nums[j];
            while(p>=k)
            {
                p=p/nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;

        
    }
};