class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,count=0;
        unordered_map<int,int>freq;
        freq[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            //to handle negative remainder
            int rem=((sum%k)+k)%k;
            if(freq.find(rem) != freq.end())
            {
                count+=freq[rem];
                
            }
            freq[rem]++;
            
        }
        return count;
        
    }
};