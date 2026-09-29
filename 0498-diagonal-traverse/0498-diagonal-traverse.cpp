class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans;
        //// Loop through every diagonal sum 'd' from 0 to (n + m - 2)
        for(int d = 0; d < n + m -1;d++){
            vector<int>temp;
            for(int i = 0; i < n ; i++){
                //i + j = d
                int j = d -i;
                if(j >= 0 && j < m){
                    temp.push_back(mat[i][j]);
                }
            }
        
        if(d % 2 == 0){
            //EVEN => reverse
            reverse(temp.begin(),temp.end());
        }
        ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return ans;
    }
};