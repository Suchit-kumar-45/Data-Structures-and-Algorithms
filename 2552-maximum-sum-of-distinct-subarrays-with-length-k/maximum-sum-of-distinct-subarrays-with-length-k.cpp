class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int req=0;
        unordered_map<int,int>freq;
        int i=0,j=0;
        long long sum=0;
        long long ans=0;
        for(int i=0;i<k;i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]]==1)
            {
                req++;
            }
        }
        while(j<k)
        {
            sum+=nums[j];
            j++;
        }
        if(req==k)
        {
            ans=max(ans,sum);
        }
        while(j<n)
        {
            freq[nums[i]]--;
            sum=sum-nums[i];
            if(freq[nums[i]]==0)
            {
                req--;
            }
            freq[nums[j]]++;
            sum=sum+nums[j];
            if(freq[nums[j]]==1)
            {
                req++;
            }
            if(req==k)
            {
                ans=max(ans,sum);
            }
            i++;
            j++;

        }
        return ans;
        
    }
};