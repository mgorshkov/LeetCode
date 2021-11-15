//
//  roman-to-integer.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
//
//Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
//I can be placed before V (5) and X (10) to make 4 and 9.
//X can be placed before L (50) and C (100) to make 40 and 90.
//C can be placed before D (500) and M (1000) to make 400 and 900.
//Given a roman numeral, convert it to an integer.

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i < s.length() - 1) {
                if (s[i] == 'I') {
                    if (s[i + 1] == 'V') {
                        result += 4;
                        i++;
                        continue;
                    } else if (s[i + 1] == 'X') {
                        result += 9;
                        i++;
                        continue;
                    }
                } else if (s[i] == 'X') {
                    if (s[i + 1] == 'L') {
                        result += 40;
                        i++;
                        continue;
                    } else if (s[i + 1] == 'C') {
                        result += 90;
                        i++;
                        continue;
                    }
                } else if (s[i] == 'C') {
                    if (s[i + 1] == 'D') {
                        result += 400;
                        i++;
                        continue;
                    } else if (s[i + 1] == 'M') {
                        result += 900;
                        i++;
                        continue;
                    }
                }
            }
            switch (s[i]) {
                case 'M':
                    result += 1000;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'C':
                    result += 100;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'X':
                    result += 10;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'I':
                    result += 1;
                    break;
                default:
                    assert(false);
            }
        }
        return result;
    }
};
