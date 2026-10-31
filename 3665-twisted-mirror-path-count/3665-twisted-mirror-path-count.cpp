class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        const int MOD = 1e9 + 7;

        // dp[2][500][2] to optimize space row-by-row
        // dp[cur][j][dir] where dir = 0 (moving right) or 1 (moving down)
        int dp[2][500][2] = {0};

        // Base case for the 0th row
        for (int j = 0; j < c; j++) {
            dp[0][j][0] = 1;
            if (grid[0][j] == 1) break; // Mirrors block straight paths
        }

        bool isM = 0;
        for (int i = 1; i < r; i++) {
            bool cur = i & 1;
            bool prev = !cur;

            // Clear current row cache
            for (int j = 0; j < c; j++) {
                dp[cur][j][0] = 0;
                dp[cur][j][1] = 0;
            }

            // 0th column boundary setup
            dp[cur][0][1] = !isM;
            isM |= grid[i][0];

            for (int j = 1; j < c; j++) {
                for (int dir = 0; dir <= 1; dir++) {
                    // If current cell is a mirror, it reflects the incoming path immediately
                    if (grid[i][j] == 1) {
                        dp[cur][j][dir] = dp[cur ^ dir][j - !dir][!dir];
                        continue;
                    }

                    // Otherwise, sum paths coming from above and from the left
                    long long step = (long long)dp[cur][j - 1][1] + dp[prev][j][0];
                    if (step >= MOD) step %= MOD;
                    dp[cur][j][dir] = step;
                }
            }
        }

        return dp[(r - 1) & 1][c - 1][0];
    }
};