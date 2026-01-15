class Solution {
public:
    void initialize(vector<int>&parent,vector<int>&rank,int n)
    {
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findParent(vector<int>&parent,int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node]=findParent(parent,parent[node]);
    }
    void unionSet(int u,int v, vector<int>&parent,vector<int>&rank)
    {
        u=findParent(parent,u);
        v=findParent(parent,v);

    
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else
        {
            parent[u]=v;
            rank[v]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1);
        vector<int>rank(n+1);
        initialize(parent,rank,n);

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(findParent(parent,u)==findParent(parent,v))
            {
                return edges[i];
            }
            unionSet(u,v,parent,rank);
        }
        return {};
    }
};