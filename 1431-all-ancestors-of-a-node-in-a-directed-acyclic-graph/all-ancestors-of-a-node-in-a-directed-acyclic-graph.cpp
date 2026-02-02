class Solution {
public:
    void dfs(int src,vector<int>&ans,unordered_map<int,list<int>>&adj, unordered_map<int,bool>&vis)
    {
        vis[src]=true;
        for(auto i:adj[src])
        {
            if(!vis[i])
            {
                ans.push_back(i);
                dfs(i,ans,adj,vis);
                vis[i]=true;
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        vector<vector<int>>ans(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            unordered_map<int,bool>vis;
            dfs(i,ans[i],adj,vis);
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
        
    }
};