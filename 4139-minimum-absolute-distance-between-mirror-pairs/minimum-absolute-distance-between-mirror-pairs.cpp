class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            int newnum=stoi(s);
            if(mp.find(newnum) != mp.end() )
            {
                vector<int>& vec = mp[newnum];
                auto it = upper_bound(vec.begin(), vec.end(), i);

                if (it != vec.end()) {
                    ans = min(ans, *it - i);
                }
            }

                
            
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
        
    }
};