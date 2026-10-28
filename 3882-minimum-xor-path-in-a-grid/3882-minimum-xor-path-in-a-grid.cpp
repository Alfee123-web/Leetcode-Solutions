class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[j] will store the bitset of reachable XOR values for column j in the current/previous row
        std::vector<std::bitset<1024>> dp(n);
        
        for (int i = 0; i < m; ++i) {
            std::vector<std::bitset<1024>> next_dp(n);
            for (int j = 0; j < n; ++j) {
                std::bitset<1024> reachable;
                
                // From top cell
                if (i > 0) {
                    for (int x = 0; x < 1024; ++x) {
                        if (dp[j].test(x)) reachable.set(x);
                    }
                }
                // From left cell
                if (j > 0) {
                    for (int x = 0; x < 1024; ++x) {
                        if (next_dp[j - 1].test(x)) reachable.set(x);
                    }
                }
                
                // Base case for starting cell (0, 0)
                if (i == 0 && j == 0) {
                    reachable.set(0);
                }
                
                // Apply current cell's grid value via XOR
                if (reachable.any()) {
                    std::bitset<1024> transformed;
                    for (int x = 0; x < 1024; ++x) {
                        if (reachable.test(x)) {
                            transformed.set(x ^ grid[i][j]);
                        }
                    }
                    next_dp[j] = transformed;
                }
            }
            dp = next_dp;
        }
        
        // Find the minimum XOR sum at the bottom-right cell (n - 1)
        for (int x = 0; x < 1024; ++x) {
            if (dp[n - 1].test(x)) {
                return x;
            }
        }
        
        return 0;
    }
};