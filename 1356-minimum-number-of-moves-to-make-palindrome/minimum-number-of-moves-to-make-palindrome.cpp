class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int st=0;
        int e=s.size()-1;
        int count=0;
        while(st<e)
        {
            if(s[st]==s[e]){
                st++;
                e--;
            }
            else
            {
                int k=e;
                while(k>st && s[k] != s[st])
                    k--;
                
                    //middle case
                    if(k==st)
                    {
                        swap(s[st],s[st+1]);
                        count++;
                    }
                     else {
                    // Move s[k] to e with adjacent swaps
                    while (k < e) {
                        swap(s[k], s[k + 1]);
                        count++;
                        k++;
                        }
                st++;
                e--;
                }

            }
        }
        return count;
        
    }
};