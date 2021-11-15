//
//  longest-substring-without-repeating-characters.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given a string s, find the length of the longest substring without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int max_length = 0;
        set<char> uniq;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
           if (uniq.find(c) == uniq.end()) {
                length++;
                if (length > max_length)
                    max_length = length;
                uniq.insert(c);
            } else {
               uniq.clear();
               length = 0;
               while (s[--i] != c)
                   ;
           }
        }
        return max_length;
    }
};
