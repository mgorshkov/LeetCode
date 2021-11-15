//
//  continuous-subarray-sum.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.
//
//An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
//

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        unordered_map<int, int> cache;
        int sum = nums[0];
        cache[sum % k] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum % k == 0) {
                return true;
            }
            auto it = cache.find(sum % k);
            if (it != cache.end()) {
                if (i - it->second >= 2) {
                    return true;
                }
            } else {
                cache[sum % k] = i;
            }
        }
        return false;
    }
};
