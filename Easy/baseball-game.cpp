//
//  baseball-game.cpp
//  
//
//  Created by Mikhail Gorshkov on 18.01.2022.
//
//You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.
//
//At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:
//
//An integer x - Record a new score of x.
//"+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
//"D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
//"C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
//Return the sum of all the scores on the record.

#include <stack>

class Solution {
public:
    int calPoints(vector<string>& ops) {
        std::stack<int> op_stack;
        int sum = 0;
        
        for (auto op: ops) {
            if (op == "D") {
                int res = op_stack.top() * 2;
                sum += res;
                op_stack.push(res);
            } else if (op == "C") {
                sum -= op_stack.top();
                op_stack.pop();
            } else if (op == "+") {
                int last = op_stack.top();
                op_stack.pop();
                int prev = op_stack.top();
                int res = prev + last;
                op_stack.push(last);
                op_stack.push(res);
                sum += res;
            } else {
                int num = atoi(op.c_str());
                op_stack.push(num);
                sum += num;
            }
        }
        return sum;
    }
};
