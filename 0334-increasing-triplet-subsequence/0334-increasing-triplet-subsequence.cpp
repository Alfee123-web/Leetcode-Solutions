class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long f = LONG_MAX;
        long s = LONG_MAX;
       for(int i = 0 ; i< nums.size(); i++){
        if(nums[i] <= f){
            f = nums[i];
        }else if(nums[i] <= s){
            s = nums[i];
        }else{
            return true;
        }
       }
       return false;
    }
};