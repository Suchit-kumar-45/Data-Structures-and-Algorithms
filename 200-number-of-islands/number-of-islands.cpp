class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] != '1')
            return;
        grid[i][j]='2';
        vector<int>row={i-1,i+1,i,i};
        vector<int>col={j,j,j-1,j+1};
        for(int index=0;index<4;index++)
        {
            dfs(row[index],col[index],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};