class Solution {
public:
    bool bfs(int src, int dest, unordered_map<int,list<int>>& adj)
    {
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();

            for(auto i:adj[front])
            {
                if(i==dest)
                {
                    return true;
                }
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
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
        if(n==1)
        {
            return true;
        }
        return bfs(source,destination,adj);
        
    }
};