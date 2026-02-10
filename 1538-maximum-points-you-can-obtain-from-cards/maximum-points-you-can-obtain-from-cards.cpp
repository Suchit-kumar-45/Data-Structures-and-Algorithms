class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_sum=0;
        int n=cardPoints.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            total_sum+=cardPoints[i];
        }
        int i=0,j=0;
        int sum=0;
        while(j<(n-k))
        {
            sum+=cardPoints[j];
            j++;
        }
         ans=min(ans,sum);
        while(j<n)
        {
            sum=sum+cardPoints[j]-cardPoints[i];
            ans=min(ans,sum);
            j++;
            i++;
        }
        return (total_sum-ans);
        
    }
};