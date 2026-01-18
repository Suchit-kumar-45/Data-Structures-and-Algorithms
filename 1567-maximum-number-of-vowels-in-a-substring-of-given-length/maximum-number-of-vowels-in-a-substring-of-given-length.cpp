class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e'|| ch=='i' || ch=='o' || ch=='u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int count=0;
        int ans=0;
        for(int right=0;right<k;right++)
        {
            if(isVowel(s[right]))
            {
                count++;
            }

        }
        ans=count;
        for(int i=k;i<s.size();i++)
            {
                if(isVowel(s[i]))
                {
                    count++;
                }
                if(isVowel(s[i-k]))
                {
                    count--;
                }
                ans=max(ans,count);

            }
        return ans;
        
    }
};
            // if(s[right]=='a' || s[right]=='e'|| s[right]=='i' || s[right]=='o' || s[right]=='u')
