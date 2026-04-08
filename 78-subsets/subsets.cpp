class Solution {
public:
    void solve(vector<int>& nums,int n,vector<int>temp,vector<vector<int>>&ans,int i)
    {
        if(i>=n)
        {
            ans.push_back(temp);
            return;
        }
        //exclude
        solve(nums,n,temp,ans,i+1);

        //exclude
        int element=nums[i];
        temp.push_back(element);
        solve(nums,n,temp,ans,i+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,n,temp,ans,i);
        return ans;
        
    }
};