class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int totSum = 0;
        for(int i = 0; i< nums.size(); i++){
          totSum += nums[i];//28
        }
        for(int i = 0 ; i <nums.size();i++ ){
            int rightSum = totSum - leftSum - nums[i]; 
            if(leftSum == rightSum){
               return i;
            }else{
                leftSum += nums[i];
            }
             
        }
     return -1;
    }
};