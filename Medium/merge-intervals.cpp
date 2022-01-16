//
//  merge-intervals.cpp
//  
//
//  Created by Mikhail Gorshkov on 16.01.2022.
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.empty())
            return result;
        std::sort(intervals.begin(), intervals.end(), [](auto left, auto right){
            return left[0] < right[0] ? true : left[0] > right[0] ? false : left[1] < right[1];
        });
        int l = intervals[0][0];
        int r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > r) {
                vector<int> v{l, r};
                result.push_back(v);
                l = intervals[i][0];
                r = intervals[i][1];
            } else if (intervals[i][1] > r) {
                r = intervals[i][1];
            }
        }
        vector<int> v{l, r};
        result.push_back(v);
        return result;
    }
};
