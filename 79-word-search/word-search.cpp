class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int m, int n, int i, int j, int k,vector<vector<bool>>&vis)
    {
        if(i>=m || j>=n || i<0 || j<0 || board[i][j]!=word[k] || vis[i][j])
        {
            return false;
        }
        if(k==word.size()-1)
            return true;
        
        vis[i][j]=true;
        bool found= solve(board,word,m,n,i+1,j,k+1,vis)||
                    solve(board,word,m,n,i-1,j,k+1,vis)||
                    solve(board,word,m,n,i,j+1,k+1,vis)||
                    solve(board,word,m,n,i,j-1,k+1,vis);
        vis[i][j]=false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(solve(board,word,m,n,i,j,0,vis))
                    return true;
            }
        }
        return false;
        
    }
};