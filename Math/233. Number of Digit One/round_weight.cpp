class Solution {
public:
    int countDigitOne(int n) {
        if(n<1) return 0;
        unsigned int round = n;
        unsigned int base = 1;
        unsigned int res = 0;
        unsigned int weight;
        while(round) {
            weight = round % 10;
            round /= 10;
            res += round * base;
            if(weight == 1) res += n%base + 1;
            else if(weight > 1) res += base;
            base *= 10;
        }
        return res;
    }
};