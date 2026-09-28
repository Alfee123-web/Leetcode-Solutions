class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int sr = 0 , sc =0;
        int er = n-1, ec = m-1;
         while(sr <= er && sc <= ec){
        // top right bottom left
        for(int j = sc ; j <= ec; j++ ){
            ans.push_back(matrix[sr][j]);
        }
        for(int i = sr+1 ; i <= er ; i++){
            ans.push_back(matrix[i][ec]);
        }
           for(int j = ec-1 ; j >= sc ; j--){
            if(sr == er){
                break;
            }
            ans.push_back(matrix[er][j]);
        }
        for(int i = er-1 ; i >= sr+1 ; i--){
            if(sc == ec){
                break;
            }
            ans.push_back(matrix[i][sc]);
        }
     sr++;
     er--;
     sc++;
     ec--;

         }
         return ans;
    }
};