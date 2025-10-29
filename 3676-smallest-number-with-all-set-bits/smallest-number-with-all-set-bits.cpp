class Solution {
public:
    int smallestNumber(int n) {
        if (n <= 1) return 1;

        int power = 1;
        while (power <= n) {
            power <<= 1; 
        }
        return power - 1;
    }
};
