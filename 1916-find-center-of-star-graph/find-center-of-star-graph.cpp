class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int ans=0;
        int row=edges.size();
        int col=edges[0].size();
        int val1=edges[0][0];
        int val2=edges[0][1];
        for(int i=1;i<row;i++)
        {
            if(edges[i][0]==val1 || edges[i][0]==val2)
            {
                ans=edges[i][0];
            }
            else
            {
                ans=edges[i][1];
            }
        }
        return ans;
        
    }
};