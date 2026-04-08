class Solution {
public:
    const int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long row=queries.size();
        for(long long i=0;i<row;i++)
        {
            int index=queries[i][0];
            while(index<=queries[i][1])
            {
                long long val=(1LL*nums[index]*queries[i][3])%mod;
                nums[index]=val;
                index=index+queries[i][2];
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=ans^nums[i];
        }
        return ans;
        
    }
};