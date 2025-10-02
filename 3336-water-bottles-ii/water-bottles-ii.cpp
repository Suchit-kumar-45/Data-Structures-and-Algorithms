class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        long long eb=0,db=0;
        while(numBottles>0)
        {
            db+=numBottles;
            eb+=numBottles;
            numBottles=0;
            while(eb>=numExchange)
            {
                numBottles+=1;
                eb-=numExchange;
                numExchange+=1;

            }
        
        }
        return db;
    }
};