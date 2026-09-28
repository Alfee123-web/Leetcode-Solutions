class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool rZero = false;
        bool cZero = false;
        // first row
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                rZero = true;
                break;
            }
        }
        // first col
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                cZero = true;
                break;
            }
        }
        // first row and col as markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // update interior cells
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // update first row
        if (rZero) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        // update first col
        if (cZero) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};