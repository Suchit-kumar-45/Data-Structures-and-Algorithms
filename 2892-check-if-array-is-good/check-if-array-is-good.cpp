class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int val=nums[n-1];
        int k=1;
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]!=k)
            {
                return false;
            }
            k++;
        }
        if(n==val+1 && nums[n-1]==nums[n-2])
        {
            return true;
        }
        return false;

        
    }
};