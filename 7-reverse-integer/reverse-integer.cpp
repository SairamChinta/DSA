class Solution {
public:
    int reverse(int x) {
        long long num = x;
        long long rev = 0;

        while (num != 0) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            if (rev > INT_MAX || rev < INT_MIN) return 0;
            num /= 10;
        }
        return (int)rev;
    }
};
