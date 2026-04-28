class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>arr;
        bool flag=true;
        int rem=grid[0][0]%x;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr.push_back(grid[i][j]);
                if(grid[i][j]%x != rem)
                {
                    flag=false;
                }
            }
        }
        if(!flag)
            return -1;
        sort(arr.begin(),arr.end());
        int ans=0;
        int val=arr[arr.size()/2];
        for(int i=0;i<arr.size();i++)
        {
            int add=abs(val-arr[i])/x;
            ans+=add;
        }
        return ans;
        
        
        

        
    }
};