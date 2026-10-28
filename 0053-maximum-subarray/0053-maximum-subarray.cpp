class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadanes algorithm
        int c = nums[0];
        int ms = nums[0];
        for(int i = 1; i < nums.size(); i++){
            c = max(nums[i] , c + nums[i]);
            ms = max(ms , c);
        }
        return ms;
    }
};