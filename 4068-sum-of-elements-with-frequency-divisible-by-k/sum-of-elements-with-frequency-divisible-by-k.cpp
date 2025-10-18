class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>freq;
        for(int num:nums)
        {
            freq[num]++;
        }
        for(auto it:freq)
        {
            if(it.second%k==0)
            {
                ans=ans+it.second*it.first;
            }
        }
        return ans;
        
    }
};