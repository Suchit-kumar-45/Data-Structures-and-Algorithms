class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int i = 0;
        int maxFreq = 0;
        int ans = 0;
        
        unordered_map<char,int> freq;
        
        for(int j = 0; j < n; j++)
        {
            freq[s[j]]++;
            
            // update maximum frequency
            maxFreq = max(maxFreq, freq[s[j]]);
            
            // if replacements needed > k → shrink
            while((j - i + 1) - maxFreq > k)
            {
                freq[s[i]]--;
                i++;
            }
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};