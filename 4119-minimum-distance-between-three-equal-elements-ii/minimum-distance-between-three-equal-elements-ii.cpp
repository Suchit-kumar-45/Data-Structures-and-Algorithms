class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>freq;
        int n=nums.size();
        for(int i=0;i<n;i++)
            {
                freq[nums[i]].push_back(i);
            }
        int ans=INT_MAX;
        bool found=false;
        for(auto &f:freq)
            {
                auto &t=f.second;
                if(t.size()<0)
                        continue;
                for(int i=0;i+2<t.size();i++)
                    {
                        int i1=t[i],i2=t[i+1],i3=t[i+2];
                        int dist=abs(i1-i2)+abs(i2-i3)+abs(i3-i1);
                        ans=min(ans,dist);
                        found=true;
                    }
            }
        if(found==true)
        {
            return ans;
        }
        return -1;
        
    }
};