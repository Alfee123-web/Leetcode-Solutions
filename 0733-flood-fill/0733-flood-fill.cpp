class Solution {
    void dfs(vector<vector<int>>& image, int r, int c, int orgColor , int newColor){
        // DFS
        int m = image.size();
        int n = image[0].size();

        // boundary condition
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != orgColor) {
            return;
        }
        //// 2. Update the color of the current pixel
        image[r][c] = newColor;

      
        dfs(image, r - 1, c, orgColor, newColor);
          dfs(image, r + 1, c, orgColor, newColor);
            dfs(image, r, c - 1, orgColor, newColor);
        dfs(image, r, c + 1, orgColor, newColor);
    
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        //base case
        if (orgColor == color) {
            return image;
        }
        dfs(image, sr, sc, orgColor, color);
        return image;
          
    }
};