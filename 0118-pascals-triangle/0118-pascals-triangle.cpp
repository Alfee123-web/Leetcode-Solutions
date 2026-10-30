class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
   
        for(int i = 0 ; i < numRows ; i++){
            vector<int>res(i + 1 , 1);//row
            for(int j = 1 ; j < i ; j++){
                res[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(res);

        }
        return ans;
    }
};
//ans[i-1][j-1] is the element directly above and to the left.

//ans[i-1][j] is the element directly above and to the right.