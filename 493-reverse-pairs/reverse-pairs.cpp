class Solution {
public:
    int  merge(vector<int>&arr,int s,int e,int mid)
    {
        int count=0;
        int len1=mid-s+1;
        int len2=e-mid;
        vector<int>arr1(len1),arr2(len2);

        for(int i=0;i<len1;i++)
        {
            arr1[i]=arr[s+i];
        }
        for(int i=0;i<len2;i++)
        {
            arr2[i]=arr[mid+i+1];
        }
        
        int j = 0;
        for (int x = 0; x < len1; x++) {
            while (j < len2 && (long long)arr1[x] > 2LL * arr2[j]) j++;
            count += j;
        }
        int i=0,k=s;
        j=0;
        while(i<len1 && j<len2)
        {
            if(arr1[i]<=arr2[j])
            {
                arr[k++]=arr1[i++];
                
            }
            else
            {
                arr[k++]=arr2[j++];
                

            }
        }
        while(i<len1)
            arr[k++]=arr1[i++];
        while(j<len2)
            arr[k++]=arr2[j++];
        return count;
    }
    int mergeSort(int s,int e,vector<int>&arr)
    {
        if(s>=e)
            return 0;
        int count=0;
        int mid=s+(e-s)/2;
        count+=mergeSort(s,mid,arr);
        count+=mergeSort(mid+1,e,arr);
        count+=merge(arr,s,e,mid);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        return mergeSort(l,r,nums);
        
    }
};