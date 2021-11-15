//
//  minimum-window-substring.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
//
//The testcases will be generated such that the answer is unique.
//
//A substring is a contiguous sequence of characters within the string.
//

class Solution {
public:
    using Counters = unordered_map<char, int>;

    Counters CalcCounters(const string& s) {
        Counters counters;
        for (auto c : s) {
            ++counters[c];
        }
        return counters;
    }

    bool CountersOK(const Counters& countersS, const Counters& countersT) {
        if (countersS.empty() && !countersT.empty())
            return false;
        for (auto counter : countersT) {
            char c = counter.first;
            int num = counter.second;
            if (countersS.find(c) == countersS.end() ||
                num > countersS.at(c)) {
                return false;
            }
        }
        return true;
    }
    
    void RemoveCharFromCounters(char c, Counters& counters) {
        auto it = counters.find(c);
        if (it == counters.end())
            return;
        if (it->second == 1) {
            counters.erase(it);
            return;
        }
        --it->second;
    }
    
    void AddCharToCounters(char c, Counters& counters) {
        ++counters[c];
    }
    
    string minWindow(string s, string t) {
        if (s.empty()) {
            return string();
        }
        Counters countersT = CalcCounters(t);
        //for (auto counter : countersT) {
        //    char c = counter.first;
        //    int num = counter.second;
        //    cout << "c=" << c << endl;
        //    cout << "num=" << num << endl;
        //}
        int left = 0;
        int right = 0;
        string minSubstring;
        int totalLength = s.length();
        int minLength = totalLength;
        Counters counters;
        while (left < totalLength) {
            int length = right - left;
            if (CountersOK(counters, countersT)) {
                if (length < minLength || minSubstring.empty()) {
                    minLength = length;
                    minSubstring = s.substr(left, length);
                }
                // shrink the window
                RemoveCharFromCounters(s[left], counters);
                //cout << "Remove " << s[left] << endl;
                left++;
            } else if (right < totalLength) {
                // expand the window
                AddCharToCounters(s[right], counters);
                //cout << "Add " << s[right] << endl;
                //cout << "counters:" << endl;
                //for (auto counter : counters) {
                //    char c = counter.first;
                //    int num = counter.second;
                //    cout << "c=" << c << endl;
                //    cout << "num=" << num << endl;
                //}
                right++;
            } else {
                break;
            }
        }
      
        return minSubstring;
    }
};
