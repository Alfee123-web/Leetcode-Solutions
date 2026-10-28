class Solution {
    void dfs(vector<vector<char>>&grid , int r , int c){
         int m = grid.size();
        int n = grid[0].size();
        if(r >= m || c >= n || r < 0 || c < 0 || grid[r][c] == '0'){
            return;
        }
        grid[r][c] = '0';//visited
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int d = 0; d < 4 ; d++){
            int new_r = r + dr[d];
            int new_c = c + dc[d];
            dfs(grid , new_r , new_c); 
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
          int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
              if(grid[i][j] == '1'){
                dfs(grid , i , j);
                island++;
              }
            }
        }
        return island;
    }
};