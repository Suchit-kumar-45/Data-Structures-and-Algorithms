class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(words[i]==target)
            {
                int val1=abs(startIndex-i);
                int val2=abs(n-val1);
                ans=min({ans,val1,val2});
            }
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
        
    }
};