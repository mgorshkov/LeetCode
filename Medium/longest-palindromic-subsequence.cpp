//516. Longest Palindromic Subsequence
//Medium
//
//5027
//
//246
//
//Add to List
//
//Share
//Given a string s, find the longest palindromic subsequence's length in s.
//
//A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
//
//
//
//Example 1:
//
//Input: s = "bbbab"
//Output: 4
//Explanation: One possible longest palindromic subsequence is "bbbb".
//Example 2:
//
//Input: s = "cbbd"
//Output: 2
//Explanation: One possible longest palindromic subsequence is "bb".
//
//
//Constraints:
//
//1 <= s.length <= 1000
//s consists only of lowercase English letters.

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        return findMaxPalindromeLen(s.c_str(), len, 0, len);
    }

private:

    struct hash_pair {
        template <typename T>
        size_t operator()(const pair<T, T>& p) const
        {
            return hash<T>{}(p.first * 10000 + p.second);
        }
    };

    using Hash = unordered_map<pair<int, int>, int, hash_pair>;

    int findMaxPalindromeLen(const char* s, int len, int left, int right) {
        auto it = lengths.find({left, right});
        if (it != lengths.end()) {
            return it->second;
        }
        if (len == 0) {
            lengths[{left, right}] = 0;
            return 0;
        }
        if (len == 1) {
            lengths[{left, right}] = 1;
            return 1;
        }
        auto first = s[0];
        auto last = s[len - 1];
        int result = first == last ?
                     2 + findMaxPalindromeLen(s + 1, len - 2, left + 1, right - 1) :
                     max(findMaxPalindromeLen(s, len - 1, left, right - 1),
                         findMaxPalindromeLen(s + 1, len - 1, left + 1, right));
        lengths[{left, right}] = result;
        return result;
    }

    Hash lengths;
};
