class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int s = 0;
        for(int i=0 ; i <n ; i++){
            for(int j  = 0 ; j < n ; j++){
                if( i == j){
                      s += mat[i][j];
                }
            }
        }
        for(int i= 0 ; i < n ; i++){
            for(int j  =0 ; j < n ; j++){
                if(j == n-i-1){
                      s += mat[i][j];
                }
            }
        }
        if(n%2 != 0){
            s = s - mat[n/2][n/2];
            return s;
        }
    return s;
        
    }
};
