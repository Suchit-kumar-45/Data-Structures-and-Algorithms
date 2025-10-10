class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0, prev = -1;
        for(int i = 0; i < 32 && n; i++){
            if(n & 1){
                if(prev != -1){
                    maxDist = max(i - prev, maxDist);
                }
                prev = i;
            }
            n >>= 1;            
        }
        return maxDist;
    }
};