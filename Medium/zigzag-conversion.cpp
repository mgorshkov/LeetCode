//
//  zigzag-conversion.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string s, int numRows);

class Solution {
public:
   string convert(string s, int numRows) {
        if (numRows == 1)
           return s;
        string result;
        for (int row = 0; row < numRows; ++row) {
            int k1 = 0, k2 = 0;
            for (int i = 0; k1 < s.length() && k2 < s.length(); ++i) {
                k1 = 2 * i * (numRows - 1) + row;
                if (k1 < s.length())
                    result += s[k1];
                
                k2 = 0;
                if (row > 0 && row < numRows -1) {
                    k2 = k1 + 2 * (numRows - 1) - 2 * row;
                    if (k2 < s.length())
                        result += s[k2];
                }
            }
        }
        return result;
    }
};
