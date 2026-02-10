class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(m>n)
            return false;
        unordered_map<char,int>freq;
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++)
        {
            freq[s1[i]]++;
        }
        int i=0,j=0;
        while(j<m)
        {
            mp[s2[j]]++;
            j++;
        }
        if(freq==mp)
        {
            return true;
        }
        
        while(j<n)
        {
            mp[s2[i]]--;
            if (mp[s2[i]] == 0)
            {
                mp.erase(s2[i]);   
            }
            mp[s2[j]]++;
            if(freq==mp)
            {
                return true;
            }
            i++;
            j++;
        }
        return false;

        
    }
};