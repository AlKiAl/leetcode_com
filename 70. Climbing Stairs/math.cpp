class Solution {

    int fib(int n) {
        double sqrt5 = sqrt(5);
        double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
        return round(fibN / sqrt5);
    }

public:
    int climbStairs(int n) {

        return fib(n+1);
    }
};
