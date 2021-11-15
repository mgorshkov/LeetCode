//
//  reverse-integer.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//
//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648)
            return 0;

        if (x < 0)
            return -reverse(-x);
        int64_t result = 0;
        int digits = static_cast<int>(log10(x)) + 1;
        for (int i = 0; i < digits; ++i)
            result += (static_cast<int>(x / pow(10, digits - i - 1)) % 10) * pow(10, i);

        if (result < (1 << 31) || result > ~(1 << 31))
            return 0;

        return result;
    }
};
