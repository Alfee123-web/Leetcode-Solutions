class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        //last element exist 
        while(s < e){
            int m = s + (e-s)/2;
            if(nums[m] < nums[e]){
                e = m;//left side 
            }else{
                s = m + 1;//right side 
            }
        }
       return nums[s];
    }
};
