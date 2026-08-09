class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();    // 5
        if( n == 0 )return false;
        int m = matrix[0].size(); // 5
        int i = 0;
        int j = m-1;
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j]  > target) {
         
                j--;
            } else {
                i++;
           
            }
          
        }

        return false;
    }
};