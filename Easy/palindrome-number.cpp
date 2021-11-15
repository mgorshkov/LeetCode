//
//  palindrome-number.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given an integer x, return true if x is palindrome integer.
//
//An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int digits = static_cast<int>(log10(x)) + 1;
        for (int i = 0; i < digits / 2; ++i)
        {
            int digit1 = (static_cast<int64_t>(x / pow(10, i)) % 10);
            int digit2 = (static_cast<int64_t>(x / pow(10, digits - i - 1)) % 10);
            if (digit1 != digit2)
                return false;
        }
        return true;
    }
};
