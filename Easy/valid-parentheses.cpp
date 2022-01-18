//
//  valid-parentheses.cpp
//  
//
//  Created by Mikhail Gorshkov on 18.01.2022.
//
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<int> stack;
        for (auto c : s) {
            if (c == '(')
                stack.push(1);
            else if (c == '{')
                stack.push(2);
            else if (c == '[')
                stack.push(3);
            else if (c == ')') {
                if (stack.empty() || stack.top() != 1)
                    return false;
                stack.pop();
            }
            else if (c == '}') {
                if (stack.empty() || stack.top() != 2)
                    return false;
                stack.pop();
            }
            else if (c == ']') {
                if (stack.empty() || stack.top() != 3)
                    return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};
