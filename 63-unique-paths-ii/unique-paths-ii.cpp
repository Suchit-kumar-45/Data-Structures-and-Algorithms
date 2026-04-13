class Solution {
public:
    
    int solve(vector<vector<int>>&obstacleGrid,int i,int j,int row, int col,vector<vector<int>>&dp)
    {
        if(i>=row || j>=col)
        {
            return 0;
        }
        if(i==row-1 && j==col-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right=0,down=0;
        if(j+1<col && obstacleGrid[i][j+1]!=1)
            right=solve(obstacleGrid,i,j+1,row,col,dp);
        if(i+1<row && obstacleGrid[i+1][j]!=1)
            down=solve(obstacleGrid,i+1,j,row,col,dp);
        return dp[i][j]=(right+down);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
            return 0;
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        return solve(obstacleGrid,0,0,row,col,dp);
        
    }
};