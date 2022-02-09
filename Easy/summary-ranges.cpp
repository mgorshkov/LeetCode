//You are given a sorted unique integer array nums.
//
//Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
//
//Each range [a,b] in the list should be output as:
//
//"a->b" if a != b
//"a" if a == b
//
//
//Example 1:
//
//Input: nums = [0,1,2,4,5,7]
//Output: ["0->2","4->5","7"]
//Explanation: The ranges are:
//[0,2] --> "0->2"
//[4,5] --> "4->5"
//[7,7] --> "7"
//Example 2:
//
//Input: nums = [0,2,3,4,6,8,9]
//Output: ["0","2->4","6","8->9"]
//Explanation: The ranges are:
//[0,0] --> "0"
//[2,4] --> "2->4"
//[6,6] --> "6"
//[8,9] --> "8->9"
//
//
//Constraints:
//
//0 <= nums.length <= 20
//-231 <= nums[i] <= 231 - 1
//All the values of nums are unique.
//nums is sorted in ascending order.

class Solution {
public:
    string outputRange(int rangeStart, int rangeEnd, vector<int>& nums) {
        string range = to_string(rangeStart);
        if (rangeStart != rangeEnd) {
            range += "->" + to_string(rangeEnd);
        }
        return range;
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty())
            return result;
        int prev = nums[0];
        int rangeStart = prev;
        int rangeEnd = prev;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != prev + 1) {
                rangeEnd = prev;
                string range = outputRange(rangeStart, rangeEnd, nums);
                result.push_back(range);
                rangeStart = nums[i];
            } else {
                rangeEnd = nums[i];
            }
            prev = nums[i];
        }
        rangeEnd = nums[nums.size() - 1];
        string range = outputRange(rangeStart, rangeEnd, nums);
        result.push_back(range);
        return result;
    }
};
