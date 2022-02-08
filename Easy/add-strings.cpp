//Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
//
//You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
//
// 
//
//Example 1:
//
//Input: num1 = "11", num2 = "123"
//Output: "134"
//Example 2:
//
//Input: num1 = "456", num2 = "77"
//Output: "533"
//Example 3:
//
//Input: num1 = "0", num2 = "0"
//Output: "0"
//
//
//Constraints:
//
//1 <= num1.length, num2.length <= 104
//num1 and num2 consist of only digits.
//num1 and num2 don't have any leading zeros except for the zero itself.
//
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int shift = 0;
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        for (;index1 >= 0 || index2 >= 0; index1--, index2--) {
            int d1 = index1 < 0 ? 0 : num1[index1] - '0';
            int d2 = index2 < 0 ? 0 : num2[index2] - '0';
            
            int d_result = d1 + d2 + shift;
            if (d_result > 9) {
                d_result %= 10;
                shift = 1;
            } else {
                shift = 0;
            }
            result.insert(0, 1, d_result + '0');
        }
        if (shift != 0) {
            result.insert(0, 1, '1');
        }
        
        return result;
    }
};
