class Solution {
public:
    void dfs(int src,unordered_map<int,list<int>>&forward,unordered_map<int,list<int>>&backward,int &ans,vector<int>&vis)
    {
        vis[src]=1;
        for(auto &i:forward[src])
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,forward,backward,ans,vis);
            }
        }

        for(auto &i:backward[src])
        {
            if(!vis[i])
            {
                dfs(i,forward,backward,ans,vis);
            }
        }
        

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>forward;
        unordered_map<int,list<int>>backward;
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            forward[u].push_back(v);
            backward[v].push_back(u);
        }
        int ans=0;
        vector<int>vis(n);
        dfs(0,forward,backward,ans,vis);
        return ans;


        
    }
};