class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0,j=0,count=0;
        int n=s.size();
        unordered_map<char,int>freq;
        while(j<3)
        {
            freq[s[j]]+=1;
            j++;
        }
        if(freq.size()==3)
        {
            count++;
        }
        while(j<n)
        {
            bool flag=true;
            freq[s[j]]++;
            freq[s[i]]--;
            for(auto val:freq)
            {
                if(val.second>1)
                {
                    flag=false;
                }
                
            }
            if(flag)
            {
                count++;
            }
            j++;
            i++;
        }

        return count;
    }
};