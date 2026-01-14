class Solution {
public:
    int solve(vector<int>& nums, int i, int j,vector<vector<int>>&dp) {
        if (i > j) return 0;

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int takeLeft = nums[i] - solve(nums, i + 1, j,dp);
        int takeRight = nums[j] - solve(nums, i, j - 1,dp);

        dp[i][j]= max(takeLeft, takeRight);
        return dp[i][j];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums, 0, n - 1,dp) >= 0;
    }
};
