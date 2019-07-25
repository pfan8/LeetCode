class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1)
            return 1.0;
        if(n < 0)
            //avoid overflow
            return 1/(x * myPow(x, -(n+ 1)));
        double t = myPow(x, n/2);
        return n & 1 ? t * t * x : t * t;
    }
};