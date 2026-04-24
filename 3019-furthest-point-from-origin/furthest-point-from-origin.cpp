class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int Rcount=0;
        int Lcount=0;
        int count=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
            {
                Lcount++;
            }
            else if(moves[i]=='R')
            {
                Rcount++;
            }
            else
            {
                count++;
            }
        }
        int maxi=max(Lcount,Rcount);
        int mini=min(Lcount,Rcount);
        int res=(maxi+count)-mini;
        return res;
        
    }
};