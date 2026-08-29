class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int currW =0;
        int maxW =0;//area = l * b
        while(i < j){
            int h = min(height[i],height[j]);
            int w = j -i;
            currW = h * w;
            maxW = max(currW , maxW);
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxW;
    }
};