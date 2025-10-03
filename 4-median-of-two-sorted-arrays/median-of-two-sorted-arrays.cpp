class Solution {
private:
    double odd( const vector<int>& nums3)
    {
        int n=nums3.size();
        int pos=(n-1)/2;
        return double(nums3[pos]);
    }
private:
    double even( const vector<int>& nums3)
    {
        int n=nums3.size();
        int pos1=(n/2)-1;
        int pos2=(n/2);
        return (nums3[pos1]+nums3[pos2])/2.0;
        
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size();
        int n=nums2.size();
        vector<int> nums3(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                nums3[k++]=nums1[i++];
                
            }
            else
            {
                nums3[k++]=nums2[j++];
            }
        }
        while(i<m)
        {
            nums3[k++]=nums1[i++];
        }
        while(j<n)
        {
            nums3[k++]=nums2[j++];
        }
        int a=nums3.size();
        if(a%2==0)
        {
          return even(nums3);
        }
         return odd(nums3);
        
        
    }
};

