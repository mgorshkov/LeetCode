//1446. Consecutive Characters
//Easy
//
//1213
//
//24
//
//Add to List
//
//Share
//The power of the string is the maximum length of a non-empty substring that contains only one unique character.
//
//Given a string s, return the power of s.
//
//
//
//Example 1:
//
//Input: s = "leetcode"
//Output: 2
//Explanation: The substring "ee" is of length 2 with the character 'e' only.
//Example 2:
//
//Input: s = "abbcccddddeeeeedcba"
//Output: 5
//Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
//
//
//Constraints:
//
//1 <= s.length <= 500
//s consists of only lowercase English letters.

class Solution {
public:
    int maxPower(string s) {
        if (s.empty())
            return 0;
        char prevLetter = s[0];
        int counter = 1;
        int maxCounter = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == prevLetter) {
                ++counter;
                if (counter > maxCounter) {
                    maxCounter = counter;
                }
            } else {
                counter = 1;
            }
            prevLetter = s[i];
        }
        return maxCounter;
    }
};
