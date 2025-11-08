class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int maxi=INT_MIN;
        int index=0;
        for(int i=0;i<row;i++)
        {
            int count=0;
            for(int j=0;j<col;j++)
            {
                if(mat[i][j]==1)
                {
                    count++;
                }
            }
            if(count>maxi)
            {
                maxi=count;
                index=i;
            }
        }
        if(maxi==INT_MIN)
        {
            maxi=0;
        }

        return {index,maxi};
    }
};