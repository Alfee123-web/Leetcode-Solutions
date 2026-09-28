class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();//2
        int m = matrix[0].size();//3
        vector<vector<int>>transposed(m , vector<int>(n));
        for(int i = 0; i< n ; i++){
            for(int j = 0; j < m; j++){
                swap(matrix[i][j],transposed[j][i]);
            }
        }
        return transposed;
    }
};