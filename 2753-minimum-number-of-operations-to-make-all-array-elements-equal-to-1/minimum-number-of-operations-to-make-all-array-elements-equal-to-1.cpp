class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int overallGCD=0;
        for(int i=0;i<n;i++)
        {
            overallGCD=gcd(overallGCD,nums[i]);
        }
        if(overallGCD != 1)
            return -1;
        else
        {
            bool allOnes = true;
            for (int x : nums)
            if (x != 1) allOnes = false;
            if (allOnes) return 0; 
        }

        if (find(nums.begin(), nums.end(), 1) != nums.end()) {
            int countOnes = 0;
            for (int x : nums) if (x == 1) countOnes++;
                return n - countOnes;  // only non-1 elements need conversion
        }


        
        int ans=INT_MAX;
        for(int i=0;i<nums.size()-1;i++)
        {
            int g=nums[i];
            for(int j=i+1;j<n;j++)
            {
                g=gcd(g,nums[j]);
                if(g==1)
                {
                    ans=min(ans,(j-i));
                    break;
                }
            }
        }
        return ans+(n-1);

        
    }
};