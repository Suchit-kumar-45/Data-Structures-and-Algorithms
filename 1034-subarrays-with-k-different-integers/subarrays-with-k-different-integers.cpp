class Solution {
public:
    int solve(vector<int>&nums,int k)
    {
        if(k<0)
            return 0;
        unordered_map<int,int>freq;
        int i=0,j=0;
        int ans=0;
        int n=nums.size();
        while(j<n)
        {
            freq[nums[j]]++;
            while(freq.size()>k)
            {
                freq[nums[i]]--;
                if(freq[nums[i]]==0)
                {
                    freq.erase(nums[i]);
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int val1=solve(nums,k);
        int val2=solve(nums,k-1);
        return (val1-val2);
        
    }
};