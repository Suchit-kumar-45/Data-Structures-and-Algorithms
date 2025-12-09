class Solution {
public:
    void dfsmark(vector<vector<char>>& grid,int r,int c,int row,int col)
    {
        if(r<0 || r>=row || c<0 || c>=col || grid[r][c] !='1')
        {
            return;
        }
        grid[r][c]='0';

        //up
        dfsmark(grid,r-1,c,row,col);
        //down
        dfsmark(grid,r+1,c,row,col);
        //left
        dfsmark(grid,r,c-1,row,col);
        //right
        dfsmark(grid,r,c+1,row,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) 
            return 0;
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(grid[r][c]=='1')
                {
                    count++;
                    dfsmark(grid,r,c,row,col);
                }
            }
        }
        return count;
        
    }
};