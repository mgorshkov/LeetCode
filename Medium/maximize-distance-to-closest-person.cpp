//You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
//
//There is at least one empty seat, and at least one person sitting.
//
//Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
//
//Return that maximum distance to the closest person.
//
//
//
//Example 1:
//
//
//Input: seats = [1,0,0,0,1,0,1]
//Output: 2
//Explanation:
//If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
//If Alex sits in any other open seat, the closest person has distance 1.
//Thus, the maximum distance to the closest person is 2.
//Example 2:
//
//Input: seats = [1,0,0,0]
//Output: 3
//Explanation:
//If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
//This is the maximum distance possible, so the answer is 3.
//Example 3:
//
//Input: seats = [0,1]
//Output: 1
//
//
//Constraints:
//
//2 <= seats.length <= 2 * 104
//seats[i] is 0 or 1.
//At least one seat is empty.
//At least one seat is occupied.

class Solution {
public:
    int findMaxDistance(int rangeStart, int rangeEnd, int size) {
        int rangeSize = rangeEnd - rangeStart;
        if (rangeStart == 0 || rangeEnd == size) {
            return rangeSize;
        }
        if (rangeSize % 2 == 0)
            return rangeSize / 2;
        return rangeSize / 2 + 1;
    }
    
    int maxDistToClosest(vector<int>& seats) {
        if (seats.size() == 0) {
            return 0;
        }
        int rangeStart = 0;
        int rangeEnd = 0;
        int prev = seats[0];
        int maxDistance = 0;
        int size = seats.size();
        for (int i = 1; i < size; ++i) {
            if (prev == 0 && seats[i] == 1) {
                rangeEnd = i;
                int distance = findMaxDistance(rangeStart, rangeEnd, size);
                if (distance > maxDistance) {
                    maxDistance = distance;
                }
            } else if (prev == 1 && seats[i] == 0) {
                rangeStart = i;
            }
            prev = seats[i];
        }
        if (prev == 0) {
            rangeEnd = size;
            int distance = findMaxDistance(rangeStart, rangeEnd, size);
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }
        return maxDistance;
    }
};
