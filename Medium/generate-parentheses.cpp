//
//  generate-parentheses.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//

class Solution {
public:
    vector<string> generate(const std::string& str, int open, int closed, int n) {
        vector<string> result;
        if (str.length() == 2 * n) {
            result.push_back(str);
            return result;
        }
        if (open < n) {
            auto res = generate(str + '(', open + 1, closed, n);
            result.insert(result.end(), res.begin(), res.end());
        }
        if (closed < open) {
            auto res = generate (str + ')', open, closed + 1, n);
            result.insert(result.end(), res.begin(), res.end());
        }
        return result;
    }
    vector<string> generateParenthesis(int n) {
        return generate("", 0, 0, n);
    }
};
