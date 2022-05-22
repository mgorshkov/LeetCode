//5. Longest Palindromic Substring
//Medium
//
//17692
//
//1051
//
//Add to List
//
//Share
//Given a string s, return the longest palindromic substring in s.
//
//
//
//Example 1:
//
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//Example 2:
//
//Input: s = "cbbd"
//Output: "bb"
//
//
//Constraints:
//
//1 <= s.length <= 1000
//s consist of only digits and English letters.

class Solution {
public:
    string longestPalindrome(const string& s) {
        int maxLen = 0;
        string maxPalindrome;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandPalindrome(i, i, s);
            int len2 = expandPalindrome(i, i + 1, s);
            int len{max(len1, len2)};
            if (len > maxLen) {
                maxLen = len;
                maxPalindrome = s.substr(i - (len - 1) / 2, len);
            }
        }
        return maxPalindrome;
    }
    
private:
    int expandPalindrome(int left, int right, const string& s) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
