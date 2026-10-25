class Solution {
private:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If out of bounds, it means the island touches the boundary (not closed)
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        // If it's water (1), it's bounded
        if (grid[r][c] == 1) {
            return true;
        }
        
        // Mark current cell as visited by changing it to 1
        grid[r][c] = 1;
        
        // Explore all 4 directions
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);
        
        return left && right && up && down;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Eliminate all land cells connected to the boundary
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(r, c, grid);
                }
            }
        }
        
        // Step 2: Count remaining closed islands in the interior
        int closedIslandsCount = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    if (dfs(r, c, grid)) {
                        closedIslandsCount++;
                    }
                }
            }
        }
        
        return closedIslandsCount;
    }
};