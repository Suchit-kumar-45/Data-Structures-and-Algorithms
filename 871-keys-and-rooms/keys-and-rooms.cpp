class Solution {
public:
int count=0;
    int solve(int src,vector<bool>&visited,unordered_map<int,list<int>>&adj)
    {
        visited[src]=true;
        for(auto &i: adj[src])
        {
                if(!visited[i])
                {
                    visited[i]=true;
                    count++;
                    solve(i,visited,adj);

                }
            
        }
        return count;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                    adj[i].push_back(rooms[i][j]);
            }

        }
        int n=rooms.size();
        vector<bool>visited(n,false);
        solve(0,visited,adj);
        if(count==n-1)
        {
            return true;
        }
        return false;
        
    }
};