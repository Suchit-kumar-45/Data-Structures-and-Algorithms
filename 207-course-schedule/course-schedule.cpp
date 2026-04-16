class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        int n=prerequisites.size();
        if(n==0)
            return true;
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
        int count=0;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            count++;
            for(auto i:adj[front])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        if(count==numCourses)
            return true;
        return false;
        
        
    }
};