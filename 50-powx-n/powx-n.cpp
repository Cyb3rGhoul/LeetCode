class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;  // Base case
        long long N = n;
        // Handle negative exponents
        if (n < 0) {
            x = 1 / x;
            N = abs(N);
        }

        // Split into smaller subproblems (divide-and-conquer)
        double half = myPow(x, N / 2);

        // If n is even: x^n = half * half
        // If n is odd:  x^n = half * half * x
        if (N % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};