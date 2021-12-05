//You are given a 0-indexed string s that you must perform k replacement operations on. The replacement operations are given as three 0-indexed parallel arrays, indices, sources, and targets, all of length k.
//
//To complete the ith replacement operation:
//
//Check if the substring sources[i] occurs at index indices[i] in the original string s.
//If it does not occur, do nothing.
//Otherwise if it does occur, replace that substring with targets[i].
//For example, if s = "abcd", indices[i] = 0, sources[i] = "ab", and targets[i] = "eee", then the result of this replacement will be "eeecd".
//
//All replacement operations must occur simultaneously, meaning the replacement operations should not affect the indexing of each other. The testcases will be generated such that the replacements will not overlap.
//
//For example, a testcase with s = "abc", indices = [0, 1], and sources = ["ab","bc"] will not be generated because the "ab" and "bc" replacements overlap.
//Return the resulting string after performing all replacement operations on s.
//
//A substring is a contiguous sequence of characters in a string.
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        struct Replacement {
            int index;
            string source;
            string target;
        };
        vector<Replacement> replacements;
        for (int i = 0; i < indices.size(); ++i) {
            replacements.push_back({indices[i], sources[i], targets[i]});
        }
        std::sort(replacements.begin(), replacements.end(), [](const auto& r1, const auto& r2) { return r1.index < r2.index; });
        
        string output;
        int index_r = 0;
        for (int i = 0; i < s.size();) {
            if (index_r < replacements.size()) {
                int index = replacements[index_r].index;
                if (i == index) {
                    if (i + replacements[index_r].source.size() <= s.size() && replacements[index_r].source == s.substr(i, replacements[index_r].source.size())) {
                        output += replacements[index_r].target;
                        i += replacements[index_r].source.size();
                        ++index_r;
                        continue;
                    } else {
                        ++index_r;
                    }
                }
            }
            output += s[i];
            ++i;
        }
        return output;
    }
};
