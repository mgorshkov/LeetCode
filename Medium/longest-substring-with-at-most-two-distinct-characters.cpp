//Description
//Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
//
//Wechat reply 【928】 get the latest requent Interview questions . (wechat id : jiuzhang15)
//
//Example
//Example 1
//Input: “eceba”
//Output: 3
//Explanation:
//T is "ece" which its length is 3.
//Example 2
//Input: “aaa”
//Output: 3
//
class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> counters;
        for (; right < s.length(); ++right) {
            char c = s[right];
            counters[c]++;
            if (counters.size() > 2) {
                counters[s[left]]--;
                if (counters[s[left]] == 0)
                    counters.erase(s[left]);
                ++left;
            }
        }
        return right - left;
    }
};
