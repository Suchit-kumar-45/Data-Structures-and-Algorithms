class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(int i=0;i<apple.size();i++)
        {
            sum+=apple[i];
        }
        sort(capacity.begin(),capacity.end());
        int n=capacity.size();
        int count=0;
        int i=n-1;
        while(sum > 0)
        {
            
            sum-=capacity[i];
            count++;
            
            i--;
            
        }
        return count;
        
    }
};