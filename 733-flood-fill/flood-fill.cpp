class Solution {
public:
    void solve(vector<vector<int>>& image, int i, int j, int color,vector<vector<bool>>&vis,int incolor)
    {
        int m=image.size();
        int n=image[0].size();
        int row[4]={i-1,i+1,i,i};
        int col[4]={j,j,j-1,j+1};
        if(i<0 || j<0 || i>=m || j>=n || image[i][j] != incolor)
        {
            return ;
        }
        vis[i][j]=1;
        image[i][j]=color;
        for(int index=0;index<4;index++)
        {
        
            solve(image,row[index],col[index],color,vis,incolor);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        int incolor=image[sr][sc];
        if(incolor==color)
            return image;
        solve(image,sr,sc,color,vis,incolor);
        return image;

        
    }
};