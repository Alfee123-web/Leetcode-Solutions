class Solution {
private:
    long long dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Mark current cell as visited by setting it to 0
        long long current_val = grid[r][c];
        grid[r][c] = 0;
        
        // 4 possible directions: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                current_val += dfs(nr, nc, grid);
            }
        }
        
        return current_val;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int valid_islands_count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long island_total = dfs(i, j, grid);
                    if (island_total % k == 0) {
                        valid_islands_count++;
                    }
                }
            }
        }
        
        return valid_islands_count;
    }
};