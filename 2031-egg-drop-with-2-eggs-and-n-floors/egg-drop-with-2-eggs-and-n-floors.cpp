class Solution {
public:
    int twoEggDrop(int n) {
        
        int cnt = 1;
        while (cnt < n) {
            n -= cnt;
            cnt++;
        }
        return cnt;
    }
};