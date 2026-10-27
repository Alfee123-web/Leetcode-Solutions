class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<int, int>> q;

        q.push({0, 0});
        grid[0][0] = 1;
        int length = 1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                if (r == n - 1 && c == n - 1) {
                    return length;
                }
                for (int d = 0; d < 8; d++) {

                    int new_r = r + dr[d];
                    int new_c = c + dc[d];

                    if (new_r >= 0 && new_c >= 0 && new_r < n && new_c < n &&
                        grid[new_r][new_c] == 0) {
                        grid[new_r][new_c] = 1;
                        q.push({new_r, new_c});
                    }
                }
            }
            length++;
        }
        return -1;
    }
};
