class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int db=0,eb=0;
        while(numBottles>0)
        {
            db+=numBottles;
            eb+=numBottles;
            numBottles=eb/numExchange;
            eb=eb%numExchange;

        }
        return db;
        
    }
};