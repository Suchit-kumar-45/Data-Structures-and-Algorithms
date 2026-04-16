class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        int n=prerequisites.size();
        //adjacenecy list
        for(int i=0;i<n;i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);

        }
        //make indegree
        vector<int>indegree(numCourses);
        for(auto i:adj)
        {
            for(auto j:i.second)
            {
                indegree[j]++;

            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        //apply bfs
        vector<int>ans;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:adj[front])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        if(ans.size()==numCourses)
            return ans;
        return {};
        
        
    }
};
