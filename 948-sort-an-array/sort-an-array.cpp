class Solution {
private:
    void merge(vector<int>&nums,int s,int e)
    {
        int mid=(s+e)/2;
        int len1=mid-s+1;
        int len2=e-mid;

        int *first=new int[len1];
        int *second=new int[len2];
        int arrayIndex=s;
        //copy array into first and second subarray
        for(int i=0;i<len1;i++)
        {
            first[i]=nums[arrayIndex++];
        }
        arrayIndex=mid+1;
        for(int i=0;i<len2;i++)
        {
            second[i]=nums[arrayIndex++];
        }

        //merge
        int index1=0;
        int index2=0;
        arrayIndex=s;
        while(index1<len1 && index2<len2)
        {
            if(first[index1]<=second[index2])
            {
                nums[ arrayIndex++]=first[index1++];
            }
            else
            {
                nums[ arrayIndex++]=second[index2++];
            }
        }
        while(index1<len1)
        {
            nums[ arrayIndex++]=first[index1++];
        }
        while(index2<len2)
        {
             nums[ arrayIndex++]=second[index2++];
        }

        // delete the dynamically allocated space
        delete[] first;
        delete[] second;
        
        
    }

    void mergeSort(vector<int> &nums,int s,int e)
    {
        int mid=(s+e)/2;
        //base condition
        if(s>=e)
        return;
        //left part
        mergeSort(nums,s,mid);
        //right part
        mergeSort(nums,mid+1,e);

        // merge
        merge(nums,s,e);

    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
        
    }
};

