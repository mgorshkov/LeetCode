//
//  two-sum.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> diffs;
        for (std::size_t index = 0; index < nums.size(); ++index)
        {
            diffs[target - nums[index]] = index;
        }
        for (std::size_t index = 0; index < nums.size(); ++index)
        {
            auto it = diffs.find(nums[index]);
            if (it != diffs.end() && index != it->second)
            {
                result.push_back(it->second);
                result.push_back(index);
                return result;
            }
        }
        return result;
    }
};

