class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long a = labs(dividend), b = labs(divisor), res = 0;
        while (a >= b) {
            long temp = b, cnt = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                cnt <<= 1;
            }
            a -= temp;
            res += cnt;
        }
        if ((dividend < 0) ^ (divisor < 0)) res = -res;
        return res;
    }
};
