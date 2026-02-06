class Solution {
public:
    bool helper(int src,int dest,unordered_map<int,list<int>>&adj,vector<bool>&vis)
    {
        if(src==dest)
        {
            return true;
        }
        vis[src]=true;
        
        for(auto i:adj[src])
        {
                
            if(!vis[i])
            {
                if(helper(i,dest,adj,vis))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        return helper(source,destination,adj,vis);
        
        
    }
};