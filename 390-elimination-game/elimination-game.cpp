class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)
        {
            return 1;
        }
        int head=1;
        int gap=1;
        int rest=n;
        bool direction=true;
        while(rest>1)
        {
            if(direction)
            {
                head+=gap;
                gap=gap*2;
                rest=rest/2;
                
            }
            else
            {
                if(rest%2==0)
                {
                    gap=gap*2;
                    rest=rest/2;
                }
                else
                {
                    head=head+gap;
                    gap=gap*2;
                    rest=rest/2;
                }
            }
            direction=!direction;

        }
        return head;
        
    }
};