//2006. Count Number of Pairs With Absolute Difference K
//Easy
//
//757
//
//17
//
//Add to List
//
//Share
//Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
//
//The value of |x| is defined as:
//
//x if x >= 0.
//-x if x < 0.
//
//
//Example 1:
//
//Input: nums = [1,2,2,1], k = 1
//Output: 4
//Explanation: The pairs with an absolute difference of 1 are:
//- [1,2,2,1]
//- [1,2,2,1]
//- [1,2,2,1]
//- [1,2,2,1]
//Example 2:
//
//Input: nums = [1,3], k = 3
//Output: 0
//Explanation: There are no pairs with an absolute difference of 3.
//Example 3:
//
//Input: nums = [3,2,1,5,4], k = 2
//Output: 3
//Explanation: The pairs with an absolute difference of 2 are:
//- [3,2,1,5,4]
//- [3,2,1,5,4]
//- [3,2,1,5,4]

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        
        int counter{0};

        std::unordered_map<int, int> counters;
        for (auto el : nums) {
            ++counters[el];
        }

        for (auto el : nums) {
            counters[el]--;
            if (counters.find(el + k) != counters.end()) {
                counter += counters[el + k];
            }
            if (counters.find(el - k) != counters.end()) {
                counter += counters[el - k];
            }
        }

        return counter;
    }
};
