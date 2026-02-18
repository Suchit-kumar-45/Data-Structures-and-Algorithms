class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int currSum=0;
        freq[0]=1;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            currSum+=nums[i];
            if(freq.find(currSum-k) != freq.end())
            {
                count+=freq[currSum-k];
            }
        
            freq[currSum]++;
            
        }
        return count;
        
    }
};