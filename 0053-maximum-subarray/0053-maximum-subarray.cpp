class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currS = nums[0];
        int maxS = nums[0];
        for(int i = 1; i< nums.size();i++){
            currS = max(nums[i] , currS + nums[i]);
            maxS = max(maxS , currS);
        }
        return maxS;
    }
};
