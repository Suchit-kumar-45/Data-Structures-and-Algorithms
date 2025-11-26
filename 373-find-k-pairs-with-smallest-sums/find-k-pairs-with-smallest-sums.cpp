class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty()) return result;

        using T = tuple<int,int,int>; 
        // (sum, i, j)

        priority_queue<T, vector<T>, greater<T>> minHeap;

        // Push first k pairs (nums1[i], nums2[0])
        for (int i = 0; i < nums1.size() && i < k; i++) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !minHeap.empty()) {

            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            result.push_back({nums1[i], nums2[j]});

            // Move to next element in nums2: (i, j+1)
            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }

        return result;
    }
};
