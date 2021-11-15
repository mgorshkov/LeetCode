//
//  valid-anagram.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given two strings s and t, return true if t is an anagram of s, and false otherwise.

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_multiset<char> map1;
        for (auto c : s)
            map1.insert(c);
        std::unordered_multiset<char> map2;
        for (auto c : t)
            map2.insert(c);

        return map1 == map2;
    }
};
