class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][10] = {false};
        bool cols[9][10] = {false};
        bool boxes[9][10] = {false};
       

        for(int r = 0; r < 9 ;r++){
            for(int c = 0; c < 9 ; c++){
                if(board[r][c] == '.'){
                    continue;
                }
                int v = board[r][c] - '0';//covert to integer
                int index = (r/3) *3 + (c/3);
                if(rows[r][v] || cols[c][v] || boxes[index][v]){
                    return false;//duplicate exists
                }
         rows[r][v] =true;
         cols[c][v] = true;
         boxes[index][v] = true;
                   }
        }
        return true;
    }
};
//The second dimension is size 10 so we can use digits 1 through 9 directly as indices.
//9 => rows , cols
