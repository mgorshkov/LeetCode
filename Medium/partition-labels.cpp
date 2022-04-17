//763. Partition Labels
//Medium
//
//7542
//
//287
//
//Add to List
//
//Share
//You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
//
//Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
//
//Return a list of integers representing the size of these parts.
//
//
//
//Example 1:
//
//Input: s = "ababcbacadefegdehijhklij"
//Output: [9,7,8]
//Explanation:
//The partition is "ababcbaca", "defegde", "hijhklij".
//This is a partition so that each letter appears in at most one part.
//A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
//Example 2:
//
//Input: s = "eccbbbbdec"
//Output: [10]
//
//
//Constraints:
//
//1 <= s.length <= 500
//s consists of lowercase English letters.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> firstPossibleOffset;
        unordered_map<char, int> lastPossibleOffset;
        for (int i = 0; i < s.size(); ++i) {
            auto c = s[i];
            if (firstPossibleOffset.find(c) == firstPossibleOffset.end()) {
                firstPossibleOffset[c] = i;
            }
            lastPossibleOffset[c] = i;
        }
        vector<pair<int, int>> offsets;
        for (auto offset: firstPossibleOffset) {
            offsets.push_back({offset.second, lastPossibleOffset[offset.first]});
        }
        std::sort(offsets.begin(), offsets.end(),
                  [](const auto& offset1, const auto& offset2) {
                      return offset1.first < offset2.first;
                  });
        int right = -1;
        vector<int> partitions;
        int last_pushed_offset = 0;
        for (const auto& offset : offsets) {
            if (right == -1)
                right = offset.second;
            if (offset.first > right) {
                // dump partition, since left bound is more than right
                int size = right + 1 - last_pushed_offset;
                partitions.push_back(size);
                last_pushed_offset = right + 1;
                right = -1;
            }
            if (offset.second > right)
                right = offset.second;
        }
        if (s.size() - last_pushed_offset > 0)
            partitions.push_back(s.size() - last_pushed_offset);
        return partitions;
    }
};
