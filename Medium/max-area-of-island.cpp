//
//  max-area-of-island.cpp
//  
//
//  Created by Mikhail Gorshkov on 15.11.2021.
//

//You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
//The area of an island is the number of cells with a value 1 in the island.
//
//Return the maximum area of an island in grid. If there is no island, return 0.

class Solution {
public:
    void enqueue(queue<pair<int, int>>& q, vector<vector<int>>& grid, int i, int j) {
        if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == 1) {
            q.push(pair(i, j));
            grid[i][j] = 2; // mark;
        }
    }
        
    int getArea(vector<vector<int>>& grid, int i, int j) {
        int area = 0;
        queue<pair<int, int>> q;
        q.push(pair(i, j));
        grid[i][j] = 2; // mark;
        while(!q.empty()) {
            auto point = q.front();
            q.pop();
            int i = point.first;
            int j = point.second;
            ++area;
            enqueue(q, grid, i + 1, j);
            enqueue(q, grid, i, j + 1);
            enqueue(q, grid, i - 1, j);
            enqueue(q, grid, i, j - 1);
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    int area = getArea(grid, i, j);
                    if (area > maxArea)
                        maxArea = area;
                }
            }
        }
        return maxArea;
    }
};
