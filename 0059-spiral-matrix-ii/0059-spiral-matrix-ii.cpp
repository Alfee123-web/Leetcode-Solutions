class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n , vector<int>(n,0));
        //rows should be a standard 1D vector of size n
        int sr = 0 , sc = 0 ;
        int er = n-1, ec = n-1;
        int c = 1;//counter
        while(c <= n * n){
            //top
            for(int i = sc ;i <= ec && c <= n * n; i++){
                ans[sr][i] = c++;
            }
            sr++;
            //right
             for(int i = sr;i <= er && c <= n * n; i++){
                ans[i][er] = c++;
            }
            ec--;
           //bottom
             for(int i = ec;i >= sc && c <= n * n; i--){
                ans[er][i] = c++;
            }
            er--;
            //right
             for(int i = er ;i >= sr && c <= n * n; i--){
                ans[i][sc] = c++;
            }
            sc++;

        }
      
return ans;
    }
};