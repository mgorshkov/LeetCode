//908 · Line Reflection
//Algorithms
//Medium
//Accepted Rate
//27%
//
//DescriptionSolutionNotesDiscussLeaderboard
//Description
//Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.
//
//Example
//Example1
//
//Input: [[1,1],[-1,1]]
//Output: true
//Example2
//
//Input: [[1,1],[-1,-1]]
//Output: false
//Challenge
//Could you do better than O(n2)?

class Solution {
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */
    bool isReflected(vector<vector<int>> &points) {
        int xMin;
        int xMax;
        bool minInited = false;
        bool maxInited = false;
        for (auto point : points) {
            if (!minInited || point[0] < xMin) {
                xMin = point[0];
                minInited = true;
            }
            if (!maxInited || point[0] > xMax) {
                xMax = point[0];
                maxInited = true;
            }
        }
        int xMiddleDoubled = xMax + xMin;
        set<pair<int, int>> reflected;
        for (auto point: points) {
            int x = point[0];
            int xReflected = xMiddleDoubled - x;
            reflected.insert({xReflected, point[1]});
        }
        
        for (auto point : points) {
            if (reflected.find({point[0], point[1]}) == reflected.end())
                return false;
        }

        return true;
    }
};
