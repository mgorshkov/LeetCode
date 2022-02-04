//There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
//
//Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
//
//Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
//
//You must decrease the overall operation steps as much as possible.
//
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        // find out pivot position
        int pivot = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                pivot = i + 1;
                break;
            }
        }
        int low;
        int high;
        if (target < nums[0] || pivot == 0) { //no split or target is on the right
           low = pivot;
           high = nums.size() - 1;
        } else { // target is of the left
           low = 0;
           high = pivot - 1;
        }
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (target == nums[middle]) {
                return true;
            } else if (target > nums[middle]) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return false;
    }
};
