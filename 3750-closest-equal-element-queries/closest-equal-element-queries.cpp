class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>ans;
        unordered_map<int,vector<int>>freq;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]].push_back(i);
        }
        for(int q:queries)
        {
            int index=q;
            int value=nums[index];
            auto &vec=freq[value];
            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            //find minimum
            int pos=lower_bound(vec.begin(),vec.end(),q)-vec.begin();

            int res=INT_MAX;
            int next=vec[(pos+1+vec.size())%vec.size()];
            int dis1=abs(next-q);
            int dis2=(n-dis1);
            res=min({res,dis1,dis2});

            int prev=vec[(pos-1+vec.size())%vec.size()];
            int dis3=abs(prev-q);
            int dis4=(n-dis3);
            res=min({res,dis3,dis4});

            if(res==INT_MAX)
                res=-1;
            ans.push_back(res);
        }
        return ans;
    }
};