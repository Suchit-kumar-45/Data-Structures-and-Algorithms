class Solution {
public:
bool dfs(int src,unordered_map<int,bool>&vis,unordered_map<int,bool>&pathvis,unordered_map<int,list<int>>&adj)
    {
        vis[src]=true;
        pathvis[src]=true;
        for(auto i:adj[src])
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathvis,adj))
                    return true;
            }
            else if(pathvis[i])
            {
                return true;
            }
            
        }
        pathvis[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        int n=prerequisites.size();
        if(n==0)
            return true;
        for(int i=0;i<n;i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);

        }
        unordered_map<int,bool>vis;
        unordered_map<int,bool>pathvis;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathvis,adj))
                    return false;
            }
        }
        return true;
        
    }
};