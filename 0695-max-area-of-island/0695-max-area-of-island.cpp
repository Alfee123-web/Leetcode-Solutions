class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        if (r >= m || c >= n || r < 0 || c < 0 || grid[r][c] == -1 || grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = -1; // visited
        int area = 1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            area += dfs(grid, new_r, new_c);
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxA = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int currarea = dfs(grid, i, j);
                    maxA = max(currarea, maxA);
                }
            }
        }
        return maxA;
    }
};