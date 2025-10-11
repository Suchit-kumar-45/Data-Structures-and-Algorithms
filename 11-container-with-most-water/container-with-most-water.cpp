class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=INT_MIN;
        int i=0;
        int j=n-1;
        while(i<j)
        {
            int area =(j-i)*min(height[i],height[j]);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
            ans=max(ans,area);
        }
        return ans;
        
    }
};