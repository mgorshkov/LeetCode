//Given a string s, find the length of the longest substring without repeating characters.
//
// 
//
//Example 1:
//
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//Example 2:
//
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//Example 3:
//
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//Constraints:
//
//0 <= s.length <= 5 * 104
//s consists of English letters, digits, symbols and spaces.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_set<char> chars;
        int left = 0;
        int right = 0;
        int max_distance = 0;
        while (right < s.length()) {
            if (chars.find(s[right]) != chars.end()) {
                // symbol is found, advance left bound
                chars.erase(s[left]);
                ++left;
            } else {
                // symbol is not found, advance right bound
                chars.insert(s[right]);
                ++right;
                int distance = right - left;
                if (distance > max_distance)
                    max_distance = distance;
            }
        }
        return max_distance;
    }
};
