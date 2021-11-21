//
//  longest-string-chain.cpp
//  
//
//  Created by Mikhail Gorshkov on 21.11.2021.
//
//You are given an array of words where each word consists of lowercase English letters.
//
//wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
//
//For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
//A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
//
//Return the length of the longest possible word chain with words chosen from the given list of words.
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const auto& word1, const auto& word2) {
            if (word1.length() < word2.length())
                return true;
            if (word1.length() > word2.length())
                return false;
            
            return word1 < word2;
        });
        std::unordered_map<string, int> max_chain_length; // string->max length of the chain finishing with this string
        for (const auto& word: words) {
            auto word_it = max_chain_length.insert({word, 1}).first;
            for (int i = 0; i < word.size(); ++i) {
                // remove i-th letter and check if we've already seen the result
                auto word_cut = word.substr(0, i) + word.substr(i + 1, word.size() - i);
                auto word_cut_it = max_chain_length.find(word_cut);
                if (word_cut_it != max_chain_length.end()) {
                    if (word_cut_it->second + 1 > word_it->second) {
                        word_it->second = word_cut_it->second + 1;
                    }
                }
            }
        }
        int max = 0;
        for (const auto& pair: max_chain_length) {
            if (pair.second > max) {
                max = pair.second;
            }
        }
        return max;
    }
};
