//279. Perfect Squares
//Medium
//
//6659
//
//293
//
//Add to List
//
//Share
//Given an integer n, return the least number of perfect square numbers that sum to n.
//
//A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
//
//
//
//Example 1:
//
//Input: n = 12
//Output: 3
//Explanation: 12 = 4 + 4 + 4.
//Example 2:
//
//Input: n = 13
//Output: 2
//Explanation: 13 = 4 + 9.
//
//
//Constraints:
//
//1 <= n <= 104

class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }
        auto it = cache.find(n);
        if (it != cache.end())
            return it->second;
        
        int minNSquares;
        bool inited = false;
        for (int i = 1; i * i <= n; ++i) {
            int NSquares = numSquares(n - i * i) + 1;
            if (!inited || NSquares < minNSquares) {
                minNSquares = NSquares;
                inited = true;
            }
        }
        cache[n] = minNSquares;
        return minNSquares;
    }
    
private:
    unordered_map<int, int> cache;
};
