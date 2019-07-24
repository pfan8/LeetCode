class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = 0;
        while(target > 0) {
            n++;
            target -= n;
        }
        return target%2 & 1 ? (n%2 & 1 ? n+2 : n+1) : n;
    }
};