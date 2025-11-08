class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int SR=0;
        int SC=0;
        int ER=row-1;
        int EC=col-1;
        int count=0;
        int total=row*col;
        vector<int> temp;
        while(count<total)
        {
             for(int j=SC;count<total && j<=EC;j++)
            {
                //int i=SR;
                temp.push_back(matrix[SR][j]);
                count++;
            }
            SR++;
            for(int i=SR;count<total && i<=ER;i++)
            {
                //int j=EC;
                temp.push_back(matrix[i][EC]);
                count++;
            }
            EC--;
            for(int j=EC;count<total && j>=SC;j--)
            {
               // int i=ER;
               temp.push_back(matrix[ER][j]);
               count++;

            }
            ER--;
            for(int i=ER;count<total && i>=SR;i--)
            {
               // int j=SC;
                temp.push_back(matrix[i][SC]);
                count++;
            }
            SC++;
        }
        return temp;
        
    }
};