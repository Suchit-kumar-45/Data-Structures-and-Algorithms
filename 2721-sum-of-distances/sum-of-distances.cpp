class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> freq;

        // store indices
        for(int i = 0; i < n; i++) {
            freq[nums[i]].push_back(i);
        }

        for(auto &it : freq) {
            vector<int> &v = it.second;
            int m = v.size();

            vector<long long> prefix(m, 0);

            // prefix sum of indices
            prefix[0] = v[0];
            for(int i = 1; i < m; i++) {
                prefix[i] = prefix[i-1] + v[i];
            }

            for(int i = 0; i < m; i++) {
                long long left = (long long)v[i]*i - (i > 0 ? prefix[i-1] : 0);
                long long right = (prefix[m-1] - prefix[i]) - (long long)v[i]*(m-i-1);

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};