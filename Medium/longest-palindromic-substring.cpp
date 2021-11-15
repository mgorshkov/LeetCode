//
//  longest-palindromic-substring.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given a string s, return the longest palindromic substring in s.

class Solution {
public:
    string longestCommonSubstring(const string& str1, const string& str2)
    {
        if(str1.empty() || str2.empty())
        {
            return "";
        }
 
        vector<int> curr(str2.size());
        vector<int> prev(str2.size());
        int maxSubstr = 0;
        string longest;
 
        for (int i = 0; i < str1.size(); ++i)
        {
            for (unsigned int j = 0; j < str2.size(); ++j)
            {
                if (str1[i] != str2[j])
                {
                    curr[j] = 0;
                }
                else
                {
                    if (i == 0 || j == 0)
                    {
                        curr[j] = 1;
                    }
                    else
                    {
                        curr[j] = 1 + prev[j-1];
                    }
                    
                    if (str2.size() - j - 1 != i - curr[j] + 1)
                        continue;
                    
                    if (maxSubstr < curr[j])
                    {
                        maxSubstr = curr[j];
                        longest.clear();
                    }

                    if (maxSubstr == curr[j])
                    {
                        longest += str1.substr(i - maxSubstr + 1, i + 1);
                    }
                }
            }
            std::swap(curr, prev);
        }
        return longest.substr(0, maxSubstr);
    }
  
    string longestPalindrome(string s) {
        auto s1 = s;
        std::reverse(s1.begin(), s1.end());
        
        return longestCommonSubstring(s, s1);
    }
};
