class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        vector<int>ans;
        int n=nums.size();
        int j=0;
        while(j<k)
        {
            q.push(make_pair(nums[j],j));
            j++;
        }
        ans.push_back(q.top().first);
        while(j<n)
        {
            
            
            q.push(make_pair(nums[j],j));

            while(!q.empty() && q.top().second<=j-k)
                q.pop();
            ans.push_back(q.top().first);
            j++;

        }
        return ans;
        
    }
};