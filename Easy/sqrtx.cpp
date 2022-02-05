//Given a non-negative integer x, compute and return the square root of x.
//
//Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
//
//Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
//

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int start = 1;
        int end = x;
        int res = 0;
     
        while (start <= end) {
            int middle = start + (end - start) / 2;
            
            int64_t pow2 = (int64_t)middle * middle;
            if (pow2 == x) {
                return middle;
            }
            else if (pow2 < x) {
                res = middle;
                start = middle + 1;
            }
            else {
                end = middle - 1;
            }
        }
        return res;
    }
};
