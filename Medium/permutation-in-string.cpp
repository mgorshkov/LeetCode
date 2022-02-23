//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//
//In other words, return true if one of s1's permutations is the substring of s2.
//
//
//
//Example 1:
//
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
//Example 2:
//
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
//
//
//Constraints:
//
//1 <= s1.length, s2.length <= 104
//s1 and s2 consist of lowercase English letters.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        unordered_map<char, int> pattern;
        for (char c: s1) {
            pattern[c]++;
        }
        int left = 0;
        int right = s1.length() - 1;
        unordered_map<char, int> m;
        for (int i = left; i <= right; ++i) {
            m[s2[i]]++;
        }
        
        while (right < s2.length()) {
            if (m == pattern) {
                return true;
            }
            right++;
            m[s2[right]]++;
            
            m[s2[left]]--;
            if (m[s2[left]] == 0)
                m.erase(s2[left]);
            left++;
        }
        return false;
    }
};
