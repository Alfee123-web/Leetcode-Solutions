class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
    
        for(int i = 0; i < n; i++){// 2 1 0
            for(int j = i+1; j < n; j++){// 0 1 2 
                swap(matrix[i][j], matrix[j][i]);//transpose

            }
        }
        for(int i = 0; i < n ; i++){
             reverse(matrix[i].begin() , matrix[i].end());
        }
      
        
    }
};