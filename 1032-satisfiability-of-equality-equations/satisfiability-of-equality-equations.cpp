class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    char findP(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        //path compression
        return parent[x]=findP(parent[x]);
    }
    void unionfun(char x, char y)
    {
        int xParent=findP(x);
        int yParent=findP(y);
        if(xParent==yParent)
        {
            return;
        }
        if(rank[xParent]<rank[yParent])
        {
            parent[xParent]=yParent;
        }
        else if(rank[xParent]>rank[yParent])
        {
            parent[yParent]=xParent;
        }
        else
        {
            parent[xParent]=yParent;
            rank[yParent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<equations.size();i++)
        {
            char sign=equations[i][1];
            if(sign=='=')
            {
                int u=equations[i][0]-'a';
                int v=equations[i][3]-'a';
                unionfun(u,v);
            }
            
        }
        for(int i=0;i<equations.size();i++)
        {
            int u=equations[i][0]-'a';
            char sign=equations[i][1];
            if(sign=='!')
            {
                int v=equations[i][3]-'a';
                int u=equations[i][0]-'a';
                if(findP(u)==findP(v))
                    return false;
            }
            
        }
        
        return true;
        
    }
};