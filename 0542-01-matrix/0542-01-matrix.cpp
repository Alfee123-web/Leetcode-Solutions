class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        int distance = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    distance++;
                } else if (mat[i][j] == 1) {
                    mat[i][j] = -1;//visited 
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int new_r = r + dr[d];
                    int new_c = c + dc[d];
                    if (new_r >= 0 && new_c >= 0 && new_r < m && new_c < n &&
                        mat[new_r][new_c] == -1) {

                        mat[new_r][new_c] = mat[r][c] + 1;
                        q.push({new_r, new_c});
                    }
                }
            }
        }
        return mat;
    }
};