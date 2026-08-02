class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n * n + 1, 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                freq[grid[i][j]]++;
            }
        }
        int r = -1;
        int m = -1;
        for (int k = 1; k <= n * n; k++) {
            if (freq[k] == 2)
                r = k;
            if (freq[k] == 0)
                m = k;
        }
        return {r, m};
    }
};