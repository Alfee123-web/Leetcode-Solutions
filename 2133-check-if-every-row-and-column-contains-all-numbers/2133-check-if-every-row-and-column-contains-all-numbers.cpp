class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
       
        for(int i = 0; i <n ; i++){
             unordered_set<int>rowSet;//unique elements 
             unordered_set<int>colSet;
          for(int j = 0; j < n ; j++){
            rowSet.insert(matrix[i][j]);
            colSet.insert(matrix[j][i]);
          }
          if(rowSet.size() != n || colSet.size() != n){
            return false;
          }

        }
        return true;
    }
};