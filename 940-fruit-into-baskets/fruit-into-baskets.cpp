class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int n=fruits.size();
        unordered_map<int,int>freq;
        int capacity=0;
        int ans=INT_MIN;
        while(j<n)
        {
            if(freq.find(fruits[j]) == freq.end() )
            {
                capacity++;
            }
            freq[fruits[j]]++;
            
            while(capacity>2 )
            {
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0)
                {
                    freq.erase(fruits[i]);
                    capacity--;
                }
                i++;

            }  

            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};