//
//  max-consecutive-ones.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given a binary array nums, return the maximum number of consecutive 1's in the array.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int max_ones = 0;
        for (int num : nums) {
            if (num == 1) {
                ones++;
                if (ones > max_ones)
                    max_ones = ones;
            } else {
                ones = 0;
            }
        }
        return max_ones;
    }
};
