class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        int sum=nums[0];
        
        sort(nums.begin()+1,nums.end());
        sum+=nums[1]+nums[2];
        return sum;
        
    }
};