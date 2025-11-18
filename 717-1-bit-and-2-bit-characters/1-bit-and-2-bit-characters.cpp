class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int i=0;
        while(i<n)
        {
            if(bits[i]==1)
            {
                if(i+2<n)
                {
                    i=i+2;
                }
                else
                {
                    return false;
                }
            }
            else if(i==n-1 && bits[i]==0)
            {
                return true;
            }
            else 
                i++;

        }
        return false;
        
    }
};