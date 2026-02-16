class Solution {
public:
    int solve(vector<int>&nums,int goal)
    {
        if(goal<0)
            return 0;
        int n=nums.size();
        int i=0,j=0;
        long long sum=0;
        int count=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>goal)
            {
                sum-=nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //sum atmost goal - sum atmost goal-1
        
        return solve(nums,goal)-solve(nums,goal-1);
        
    }
};