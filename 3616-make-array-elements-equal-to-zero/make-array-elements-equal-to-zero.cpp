class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int count = 0, n = nums.size();
        int sum = 0, halfSum = 0;

        for (int num : nums) sum += num;

        for (int i = 0; i < n; i++) {
            halfSum += nums[i];
            if (nums[i] == 0) {
                if (2 * halfSum == sum) {
                    count += 2;
                } else if (abs(sum - 2 * halfSum) == 1) {
                    count++;
                } 
            }
        }
        
        return count;
    }
};