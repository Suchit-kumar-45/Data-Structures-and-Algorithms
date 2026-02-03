class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false; // minimum length

        int i = 0;

        // strictly increasing
        while(i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        if(i == 0) return false;  // no increase

        // strictly decreasing
        while(i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        if(i == n - 1) return false; // no final increase

        // strictly increasing
        while(i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};
