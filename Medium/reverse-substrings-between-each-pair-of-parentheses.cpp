//
//  reverse-substrings-between-each-pair-of-parentheses.cpp
//  
//
//  Created by Mikhail Gorshkov on 17.11.2021.
//
//You are given a string s that consists of lower case English letters and brackets.
//
//Reverse the strings in each pair of matching parentheses, starting from the innermost one.
//
//Your result should not contain any brackets.

class Solution {
public:
    void reverse(string& s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            std::swap(s[i], s[s.size() - 1 - i]);
        }
    }
    
    string reverseParentheses(string s) {
        string output;
        for (int i = 0; i < s.size(); ) {
            char c = s[i];
            if (c != '(' && c != ')') {
                output += c;
            }
            if (c == '(') {
                // find the matching bracket
                int count = 1;
                int pos = i + 1;
                for (; pos < s.size(); ++pos) {
                    if (s[pos] == '(')
                        ++count;
                    else if (s[pos] == ')')
                        --count;
                    if (count == 0)
                        break;
                }
                assert(count == 0);
                auto sub = s.substr(i + 1, pos - i - 1);
                auto str = reverseParentheses(sub);
                reverse(str);
                output += str;
                i = pos + 1;
            } else {
                ++i;
            }
        }
        return output;
    }
};
