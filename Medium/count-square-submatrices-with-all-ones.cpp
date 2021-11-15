//
//  count-square-submatrices-with-all-ones.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;
        int height = matrix.size();
        int width = matrix[0].size();
        int size = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = min(matrix[i-1][j], min(matrix[i][j-1], matrix[i-1][j-1])) + 1;
                }
                size += matrix[i][j];
            }
        }
        return size;
    }
};
