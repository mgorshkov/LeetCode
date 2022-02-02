//Given a non-negative integer x, compute and return the square root of x.
//
//Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
//
//Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
//

class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x;
     
        while (start <= end) {
            int middle = start + (end - start) / 2;
            
            auto current_square_less = [&]() {
                return middle < x / middle;
            };
            auto current_square_less_or_equal = [&]() {
                return middle <= x / middle;
            };
            auto next_square_less = [&]() {
                return middle + 1 < x / (middle + 1);
            };
            auto next_square_equals = [&]() {
                return middle + 1 == x / (middle + 1);
            };
            auto next_square_more = [&]() {
                return middle + 1 > x / (middle + 1);
            };
            
            if (current_square_less_or_equal() && next_square_more()) {
                return middle;
            }
            else if (current_square_less() && next_square_less()) {
                start = middle + 1;
            }
            else if (next_square_equals()) {
                return middle + 1;
            }
            else {
                end = middle - 1;
            }
        }
        return 0;
    }
};
