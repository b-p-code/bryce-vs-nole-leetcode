class Solution {
public:
    int mySqrt(int x) {
        // Simple solution
        // Speed: 14.92%
        // Memory: 28.41%

        long i = 0;
        while (i * i <= (long)x) {
            i++;
        }

        return i == 0 ? 0 : i - 1;
    }
};