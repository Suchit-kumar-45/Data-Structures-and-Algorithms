class Solution {
public:
    void bfs(int src, unordered_map<int,list<int>>& adj, int &nodes,int &edges,unordered_map<int,bool>&visited)
    {
        queue<int>q;
        q.push(src);
        visited[src]=true;
       
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            //count nodes
            nodes++;
            //count vertices (count double count hoga becoz undirected graph hai)
            edges+=adj[front].size();

            for(auto i:adj[front])
            {
                
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                   
                }
                
            }

        }
        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool>visited;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int nodes=0;
                int edges=0;
                bfs(i,adj,nodes,edges,visited);

                edges=edges/2;

                if(edges== nodes*(nodes-1)/2)
                    count++;
            }
        }
        
        
        return count;
        
        
    }
};