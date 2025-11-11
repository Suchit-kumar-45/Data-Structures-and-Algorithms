class Solution {
public:
    
    int solve(int n,vector<int>&arr)
    {
        if(n==0)
            return 0;
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i]>ans.back())
            {
                ans.push_back(arr[i]);
            }
            else
            {
                //find just greater element index in ans
                int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[index]=arr[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int m=envelopes.size();

        // Step 1: Sort envelopes
        // Width ascending, and if same width → height descending
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            ans.push_back(envelopes[i][1]);
        }
        return solve(m,ans);
        
    }
};