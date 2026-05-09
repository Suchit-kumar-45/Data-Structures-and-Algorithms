class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unionfind(int x,int y)
    {
        int xpar=find(x);
        int ypar=find(y);
        if(xpar==ypar)
        {
            return;
        }
        if(rank[xpar]>rank[ypar])
        {
            parent[ypar]=xpar;
        }
        else if(rank[xpar]<rank[ypar])
        {
            parent[xpar]=ypar;
        }
        else
        {
            parent[xpar]=ypar;
            rank[ypar]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    unionfind(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                count++;
        }
        return count;
    }
};