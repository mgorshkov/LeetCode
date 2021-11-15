//
//  string-to-integer-atoi.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
//
//The algorithm for myAtoi(string s) is as follows:
//
//Read in and ignore any leading whitespace.
//Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
//Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
//Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
//If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
//Return the integer as the final result.
//Note:
//
//Only the space character ' ' is considered a whitespace character.
//Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        if (str.empty())
            return 0;
        
        while (str[i] == ' ') {
            ++i;
        }
        bool negation = false;
        if (str[i] == '+')
            ++i;
        else if (str[i] == '-') {
            negation = true;
            ++i;
        }
        int64_t result = 0;
        for (; i < str.length(); ++i) {
            if (str[i] < '0' || str[i] > '9') {
                break;
            }
            int digit = str[i] - '0';
            result *= 10;
            if (negation) {
                result -= digit;
            } else {
                result += digit;
            }
            if (result < INT_MIN)
                return INT_MIN;
            if (result > INT_MAX)
                return INT_MAX;
        }
        return (int)result;
    }
};
