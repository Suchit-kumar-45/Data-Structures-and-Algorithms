class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0,j=0;
        int count=0;
        int sum=0;
        int n=arr.size();
        while(j<k)
        {
            sum+=arr[j];
            j++;
        }
        if(sum/k>=threshold)
        {
            count++;
        }
        while(j<n)
        {
            sum=sum+arr[j]-arr[i];
            if(sum/k>=threshold)
            {
                count++;
            }
            i++;
            j++;
        }
        return count;
        
    }
};