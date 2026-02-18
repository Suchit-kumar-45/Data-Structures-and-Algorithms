class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int index=0,Ycount=0,Ncount=0;
        int ans=INT_MAX;
        vector<int>arr1(n+1,0);
        vector<int>arr2(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y')
            {
                arr1[i+1]=arr1[i]+1;
                arr2[i+1]=arr2[i]+0;
            }
            else
            {
                arr1[i+1]=arr1[i]+0;
                arr2[i+1]=arr2[i]+1;
            }
        }
        for(int i=0;i<=n;i++)
        {
            int val=arr2[i]+(arr1[n]-arr1[i]);
            if(val<ans)
            {
                ans=val;
                index=i;
            }


        }
        
        return index;
        
    }
};