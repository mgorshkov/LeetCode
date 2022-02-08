//Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
//
//
//Example 1:
//
//Input: s = "Let's take LeetCode contest"
//Output: "s'teL ekat edoCteeL tsetnoc"
//Example 2:
//
//Input: s = "God Ding"
//Output: "doG gniD"
// 
//
//Constraints:
//
//1 <= s.length <= 5 * 104
//s contains printable ASCII characters.
//s does not contain any leading or trailing spaces.
//There is at least one word in s.
//All the words in s are separated by a single space.

`class Solution {
public:
    string reverseWords(string s) {
        // reverse the whole line
        for (size_t i = 0; i < s.size() / 2; ++i) {
            swap(s[s.size() - 1 - i], s[i]);
        }
        // reverse the line word by word
        string result;
        size_t i = 0;
        bool first_word = true;
        while (i < s.size()) {
            string word;
            for (; i < s.size() && s[i] != ' '; ++i) {
                word += s[i];
            }
            ++i;
            result = word + (first_word ? "" : " ") + result;
            first_word = false;
        }
        return result;
    }
};
