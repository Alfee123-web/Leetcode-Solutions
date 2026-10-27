class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {//rotten 
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
            return 0;
        
        int minutes = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();// Get the coordinates
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int new_r = r + dr[d];
                    int new_c = c + dc[d];

                   //if the orange is fresh
                    if (new_r >= 0 && new_c >= 0 && new_r < m && new_c < n &&
                        grid[new_r][new_c] == 1) {

                        grid[new_r][new_c] = 2;//rotten turn 
                        fresh--;
                        q.push({new_r, new_c});// Push to queue for the next minute
                        rotted = true;
                    }
                }
            }

            if (rotted) {
                minutes++;
            }
        }
        //  If fresh oranges remain, it's impossible to rot all of them

        return fresh == 0 ? minutes : -1;
    }
};