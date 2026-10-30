class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size()-1;
        int currA = 0;
        int maxA = 0;
        while(s < e){
            int ht  = min(height[s], height[e]);
            int w = e - s ;
            currA = ht * w;
            maxA = max(currA , maxA);
            if(height[s] < height[e]){
                s++;
            }else{
                e--;
            }
        }
        return maxA;
    }
};