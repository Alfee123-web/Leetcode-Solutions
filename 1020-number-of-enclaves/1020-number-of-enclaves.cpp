class Solution {
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();
        if (r >= n || c >= m || r < 0 || c < 0 || grid[r][c] == 0) {
            return;
        }
        grid[r][c] = 0; // visited
            
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int moves = 0;
        //first and last row
        for(int j = 0; j < m; j++){//col change
            if(grid[0][j] == 1){
                dfs(grid , 0 , j);
            }
            if(grid[n-1][j] == 1){
                dfs(grid , n-1, j);
            }
        }
        //first and last col
        for(int i = 0; i < n; i++){//row change
            if(grid[i][0] == 1){
                dfs(grid , i , 0);
            }
            if(grid[i][m-1] == 1){
                dfs(grid , i , m-1);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                
                       moves++;
                }
            }
        }
        return moves;
    }
};
