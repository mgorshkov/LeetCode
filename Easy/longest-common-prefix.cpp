//
//  longest-common-prefix.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string result;
        int count = 0;
        while (1) {
            char prevSym = '\0';
            for (int i = 0; i < strs.size(); ++i) {
                if (strs[i].length() > result.size()) {
                    if (prevSym != '\0' && strs[i][count] != prevSym) {
                        return result;
                    } else {
                        prevSym = strs[i][count];
                    }
                } else {
                    return result;
                }
            }
            ++count;
            result += prevSym;
        }
        assert(0);
        return "";
    }
};
