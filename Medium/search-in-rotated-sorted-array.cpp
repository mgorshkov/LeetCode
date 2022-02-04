//There is an integer array nums sorted in ascending order (with distinct values).
//
//Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
//
//Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
//
//You must write an algorithm with O(log n) runtime complexity.
//

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int low = 0;
        int high = nums.size() - 1;
        int last = nums[high];
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (nums[middle] > last) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        int index = low; // index of split
        if (target < nums[0] || index == 0) { //no split or target is on the right
           low = index;
           high = nums.size() - 1;
        } else { // target is of the left
           low = 0;
           high = index - 1;
        }
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (target == nums[middle]) {
                return middle;
            } else if (target > nums[middle]) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return -1;
    }
};
