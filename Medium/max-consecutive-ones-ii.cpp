//Description
//Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
//
//Wechat reply the 【883】 get the latest frequent Interview questions . (wechat id : jiuzhang15)
//
//The input array will only contain 0 and 1.
//The length of input array is a positive integer and will not exceed 10,000.
//
class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        // [1, 0, 1, 1, 0] -> 4
        // [1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0] -> 6
        int credit = 1;
        int left = 0;
        int right = 0;
        int countZeros = 0;
        for (; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                ++countZeros;
            }
            if (credit < countZeros && nums[left++] == 0) {
                --countZeros;
            }
        }
        return right - left;
    }
};
