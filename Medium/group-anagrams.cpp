//49. Group Anagrams
//Medium
//
//8975
//
//310
//
//Add to List
//
//Share
//Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//
//
//
//Example 1:
//
//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//Example 2:
//
//Input: strs = [""]
//Output: [[""]]
//Example 3:
//
//Input: strs = ["a"]
//Output: [["a"]]
//
//
//Constraints:
//
//1 <= strs.length <= 104
//0 <= strs[i].length <= 100
//strs[i] consists of lowercase English letters.

struct Hash {
    template <typename Key, typename Value>
    auto operator()(const unordered_map<Key, Value> &p) const -> size_t {
        std::size_t result = 0;
        for (auto element : p) {
            result ^= std::hash<Key>{}(element.first);
            result ^= std::hash<Key>{}(element.second);
        }
        return result;
    }
};

class Solution {
public:
    using Counter = unordered_map<char, int>;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<Counter, vector<string>, Hash> counters;
        for (const auto& str: strs) {
            Counter counter;
            for (auto c : str) {
                counter[c]++;
            }
            counters[counter].push_back(str);
        }
        vector<vector<string>> results;
        for (auto counter: counters) {
            results.push_back(counter.second);
        }
        return results;
    }
};
