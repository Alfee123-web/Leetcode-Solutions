class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();    // 5
        int m = matrix[0].size(); // 5
        int s = 0;
        int e = m - 1; // 4
        while (s < n && e >= 0) {

            if (matrix[s][e] == target) {
                return true;
            } else if (matrix[s][e] > target) { // 7 < 5 false
                e--;

            } else {
                s++;
            }
        }
        return false;
    }
};