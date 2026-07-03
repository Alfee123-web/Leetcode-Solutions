class Solution {
public:
    int trap(vector<int>& height) {
        int leftM= 0 ;
        int rigM= 0 ;
        int water = 0;
        int i = 0;
        int j = height.size()-1;
        while(i <j){
            leftM = max(leftM , height[i]);
            rigM = max(rigM , height[j]);
            if(leftM < rigM){
                water += leftM - height[i];
                i++;
            }else{
                water += rigM - height[j];
                j--;
            }
        }
        return water;
    }
};