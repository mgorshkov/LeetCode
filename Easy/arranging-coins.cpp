//You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
//
//Given the integer n, return the number of complete rows of the staircase you will build.
//

class Solution {
public:
    int evaluateRows(int rows, int coins) {
        int curr = (double)coins * 2 / rows;
        int next = (double)coins * 2 / (rows + 1);
        if (curr >= rows + 1 && next < rows + 2)
            return 0;
        if (curr < rows + 1 && next < rows + 2)
            return -1;
        return 1;
    }
    
    int arrangeCoins(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            int res = evaluateRows(middle, n);
            if (res == 0)
                return middle;
            if (res > 0)
                low = middle + 1;
            else
                high = middle - 1;
        }
        return 0;
    }
};
