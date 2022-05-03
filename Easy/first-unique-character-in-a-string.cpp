//387. First Unique Character in a String
//Easy
//
//4905
//
//195
//
//Add to List
//
//Share
//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
//
//
//
//Example 1:
//
//Input: s = "leetcode"
//Output: 0
//Example 2:
//
//Input: s = "loveleetcode"
//Output: 2
//Example 3:
//
//Input: s = "aabb"
//Output: -1
//
//
//Constraints:
//
//1 <= s.length <= 105
//s consists of only lowercase English letters.

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty())
            return -1;
        unordered_map<char, int> counters;
        for (auto c : s) {
            counters[c]++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (counters[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
